#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000\n";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000\n";
		return 0;
	}
	int s=b[2]-'A';
	int ss=d[2]-'A';
	if((s<=2&&ss<=2)||(s>2&&ss>2)){
		cout<<1;
	}else{
		cout<<"00\n";
		return 0;
	}
	if(((s<=2&&ss<=2)&&abs(ss-s)==1)||(s>2&&ss>2)){
		cout<<1<<'\n';
	}else{
		cout<<0<<'\n';
	}
	return 0;
}

