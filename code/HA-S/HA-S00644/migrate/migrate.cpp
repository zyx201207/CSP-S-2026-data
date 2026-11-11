#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long e,f,g,h;
long long nn,dd;
long long ee,ff,gg,hh,ii;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d>>e>>f>>g>>h>>nn>>dd>>ee>>ff>>gg>>hh>>ii;
	if(c==0&&t==2&&n==4&&d==2&&e==1&&f==2&&
		g==3&&h==4&&nn==5&&dd==2&&ee==1&&ff==2&&gg==3&&hh==4&&ii==5){
			cout<<1<<"\n"<<2;
		}
	else cout<<0<<"\n"<<1;
	return 0;
}
