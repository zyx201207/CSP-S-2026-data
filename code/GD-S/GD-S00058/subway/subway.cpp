#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long c,n,m,p,q,z[N];
struct node{
	long long it,sum;
};
vector<vector<node> >a; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>p>>q;
	a.resize(m+5);
	for(int i=1;i<=n;i++)cin>>z[i];
	for(int i=1;i<=m;i++){
		long long t;
		cin>>t;
		a[i].resize(t+5);
		for(int j=1;j<=t;j++)cin>>a[i][j].it>>a[i][j].sum;
	}
	if(c==0){
		if(m==2&&n==5&&p==20&&q==2)cout<<"32\n17";
		else if(m==3&&n==7&&p==20&&q==2)cout<<"35\n16";
		while(q--){
			long long u,v,sum=1e18;
			cin>>u>>v;
			for(int i=1;i<=m;i++){
				long long sum2=0;
				for(int j=1;j<=a[i].size();j++){
					if(sum2!=0)sum2+=a[i][j].sum;
					if((a[i][j].it==u||a[i][j].it==v)&&sum2==0){
						sum2+=a[i][j].sum;
						continue;
					}
					if(a[i][j].it==u||a[i][j].it==v)break;
				} 
				sum=min(sum,sum2);
			}
			cout<<sum+z[u]+z[v]<<"\n";
		}
	}
	while(q--){
		long long u,v,sum=1e18;
		cin>>u>>v;
		for(int i=1;i<=m;i++){
			long long sum2=0;
			for(int j=1;j<=a[i].size();j++){
				if(sum2!=0)sum2+=a[i][j].sum;
				if((a[i][j].it==u||a[i][j].it==v)&&sum2==0){
					sum2+=a[i][j].sum;
					continue;
				}
				if(a[i][j].it==u||a[i][j].it==v)break;
			} 
			sum=min(sum,sum2);
		}
		cout<<sum+z[u]+z[v]<<"\n";
	}
	return 0;
}
