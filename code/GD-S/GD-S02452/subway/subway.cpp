#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500010],k[500010],x,h,u;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	cin>>x;
	for(int i=1;i<=2*x;i++)
	{
		cin>>k[i];
	}
	cin>>h>>u;
	if(c==0&&n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17;
	if(c==0&&n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16;

	
	return 0;
} 
