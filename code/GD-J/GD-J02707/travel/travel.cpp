#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;string b,d;cin>>a>>b>>c>>d;
	bool bs=(b[2]<='C'),ds=(d[2]<='C');
	bool a1,a2,a3,a4;
	a1=(a==c);
	a2=a1&&(b.substr(0,2)==d.substr(0,2));
	a3=a2&&(bs==ds);
	if(b<d){
		string k=b;
		b=d;d=k;
	}
	a4=a3&&(b[2]-d[2]==1);
	//cerr<<bs<<ds<<'\n';
	cout<<a1<<a2<<a3<<a4;
	
	return 0;
}
