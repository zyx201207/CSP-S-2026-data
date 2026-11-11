#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;

	int p1,p2;
	char tmp;
	tmp=(int)(s1[0]-'0');
	p1=tmp;
	tmp=(int)(s1[1]-'0');
	p1=p1*10+tmp;

	tmp=(int)(s2[0]-'0');
	p2=tmp;
	tmp=(int)(s2[1]-'0');
	p2=p2*10+tmp;

    if(p1==p2) cout<<1;
    else cout<<0;

    char z1=s1[2];
    char z2=s2[2];
    if(z1>='A' && z1<='C' && z2>='A' && z2<='C'){
        cout<<1;
        if((z1+1 == z2) || (z2+1 == z1)) cout<<1;
        else cout<<0;
    }else if((z1=='D' || z1=='F') && (z1=='D' || z1=='F')){
        cout<<"11";
    }else{
        cout<<"00";
    }
//	cout<<p1<<p2;
	return 0;
}
