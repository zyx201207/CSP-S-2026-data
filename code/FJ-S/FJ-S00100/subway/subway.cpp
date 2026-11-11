#include<bits/stdc++.h> 
using namespace std;
vector<vector<int> > v;
long long a[214514],t[214514][514],mp[514][514],vis[214514];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	int A,B,n,m,q,k,x,y;
	cin>>A>>n>>m>>B>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			mp[i][j]=1145141919810;
			if(i==j)mp[i][j]=0;
		}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			int kk=vis[x];
			for(int l=0;l<kk;l++){
				mp[i][v[x][l]]=min(mp[i][v[x][l]],t[x][v[x][l]]+y);
				mp[v[x][l]][i]=mp[i][v[x][l]];
			}v[x].push_back(i),vis[x]++;
			t[x][i]=y;
		} 
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int l=1;l<=n;l++){
				if(i==l||j==l)continue;
				mp[i][j]=min(mp[i][j],mp[i][l]+mp[l][j]);
			}
		}
	long long ans=1145141919810;
	while(q--){
		cin>>x>>y;
		int at=vis[x],bt=vis[y];
		for(int i=0;i<at;i++)
			for(int j=0;j<bt;j++)
				ans=min(ans,mp[v[x][i]][v[y][j]]+t[x][v[x][i]]+t[y][v[y][j]]);
		cout<<ans+a[x]+a[y]<<"\n";
		ans=1145141919810;
	}
	return 0;
}//MaybeAFO 
