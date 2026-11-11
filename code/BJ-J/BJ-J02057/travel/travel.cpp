#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,c,d;
	char c1,c2;
	cin>>a>>b;
	cin>>c1;
	cin>>c>>d;
	cin>>c2;
	//cout<<a<<" "<<c1;
    if(a==c)cout<<1;
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    if(b==d)cout<<1;
    else{
        cout<<"000"<<endl;
        return 0;
    }
    if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))cout<<1;
    else{
        cout<<"00"<<endl;
        return 0;
    }
    if(((c1<='C'&&c2<='C')&&abs(c1-c2)==1)||(c1>='D'&&c2>='D'))cout<<1<<endl;
    else cout<<"0"<<endl;

	//cout<<a<<" "<<b;
	//cout<<"\n"<<a+b;
	return 0;
}
