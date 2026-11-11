#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,a,b,s,k,ti,ans,w[500010],mp[510][510],xl[500010][510],xx[500010];
bool f=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,-1,sizeof(mp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			mp[a][i]=b;
			xl[a][i]=1;
			s++;
			xx[s]=a;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(xl[x][i]==1&&xl[y][i]==1){
				ti=mp[x][i]+mp[y][i]+w[x]+w[y];
				f=1;
			}
			if(i==1)ans=ti;
			else ans=min(ans,ti);
		}
		if(f==0){
			ti=0,ans=INT_MAX;
			sort(xx+1,xx+1+s);
			for(int i=2;i<=s;i++){
				if(xx[i]==xx[i-1]){
					for(int j=1;j<=n;j++){
						ti+=mp[xx[i]][j];
					}
					ti+=mp[x][1]+mp[y][n]+w[x]+w[y];
				}
				else continue;
				ans=min(ans,ti);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
