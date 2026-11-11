#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll id,t;
};
ll kind,n,m,d,q;
ll w[500100],b[510][510];
vector<node>a[510];
vector<node>c[500100];
bool cmp(node x,node y){
	return x.id<y.id;
}
int main(){
	ll i,j,k;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>kind>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		node x;
		for(j=1;j<=k;j++){
			cin>>x.id>>x.t;
			a[i].push_back(x);
			ll u=x.id;
			x.id=i;
			c[u].push_back(x);
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) 
	b[i][j]=1e18;
	for(i=1;i<=n;i++) b[i][i]=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++){
		//cout<<i<<endl;
		if(i==j) continue;
		if(a[i].size()>a[j].size()) continue;
		for(k=a[i].size()-1;k>=0;k--){
			ll p=-1,l=0,r=a[j].size()-1;
			while(l<=r){
				ll mid=(l+r)/2;
				if(a[i][k].id==a[j][mid].id){
					p=mid;
					break;
				}
				else if(a[i][k].id>a[j][mid].id) l=mid+1;
				else r=mid-1;
				//cout<<l<<" "<<r<<endl;
			}
			if(p==-1) continue;
			b[i][j]=min(b[i][j],a[i][k].t+a[j][p].t);
			b[j][i]=min(b[j][i],a[i][k].t+a[j][p].t);
			if(kind>=12&&kind<=19) break;
		}
	}
	//cout<<"dd";
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j)
	b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	/*for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) cout<<b[i][j]<<" ";
		cout<<endl; 
	}*/
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(i=0;i<c[x].size();i++)
		for(j=0;j<c[y].size();j++){
			//cout<<c[x][i].t<<" "<<c[y][j].t<<endl;
			ans=min(ans,w[x]+w[y]+b[c[x][i].id][c[y][j].id]+c[x][i].t+c[y][j].t);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
