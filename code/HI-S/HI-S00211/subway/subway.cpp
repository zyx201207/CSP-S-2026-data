#include<bits/stdc++.h>
using namespace std;
long long n,m,d,c,q,k,w[500010],t[510][510],aij,tij,x,y,ans;
vector< pair<long long,long long> > h[500010];//¼ÇÂ¼Ñ¯ÎÊ 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aij>>tij;
			h[aij].push_back({tij,i});
		}
	}
	for(int i=1;i<=503;i++){
		for(int j=1;j<=503;j++){
			t[i][j]=1e15;
		}
	}
	for(int l=1;l<=m;l++){
		long long sz=h[l].size();
		for(int i=0;i<sz;i++){
			for(int j=i+1;j<sz;j++){
				if(t[h[l][i].second][h[l][j].second]>h[l][i].first+h[l][j].first){
					t[h[l][i].second][h[l][j].second]=h[l][i].first+h[l][j].first;
					t[h[l][j].second][h[l][i].second]=h[l][i].first+h[l][j].first;
				}
				//cout<<t[h[l][i].second][h[l][j].second]<<" "<<h[l][i].first<<" "<<h[l][j].first;
			}
			//cout<<h[l][i].first<<" ";
		}
		//cout<<endl;
	}
	for(int kk=1;kk<=n;kk++){
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=n;jj++){
				if(ii==jj)t[ii][jj]=0;
				if(t[ii][jj]>t[ii][kk]+t[kk][jj])t[ii][jj]=t[ii][kk]+t[kk][jj];
			}
			for(int jj=1;jj<=n;jj++){
				//cout<<t[ii][jj]<<" ";	
			}
		//cout<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=1e15;
		long long sz1=h[x].size(),sz2=h[y].size();
		for(int i=0;i<sz1;i++){
			for(int j=0;j<sz2;j++){
				ans=min(t[h[x][i].second][h[y][j].second]+h[x][i].first+h[y][j].first,ans);
				//cout<<t[h[x][i].second][h[y][j].second]+h[x][i].first+h[y][j].first<<" ";
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
