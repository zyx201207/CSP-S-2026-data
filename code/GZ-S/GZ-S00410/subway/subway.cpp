//GZ-S00410 ª∆∫∆è™
#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500010];
map< int,int>  dis[500100];
vector<int> mpl[500100];
int mp[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,a,t;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(mp,0x3f,sizeof(mp));
	for(int i=0;i<n;i++){
		cin>>k;
		mp[i][i]=0;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			mpl[a].push_back(i);
			dis[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++){
		if(mpl[i].size()>1){
			for(int j=0;j<mpl[i].size();j++){
				for(int k=j+1;k<mpl[i].size();k++){
					mp[mpl[i][j]][mpl[i][k]]=min(mp[mpl[i][j]][mpl[i][k]],dis[i][mpl[i][j]]+dis[i][mpl[i][k]]);
					mp[mpl[i][k]][mpl[i][j]]=mp[mpl[i][j]][mpl[i][k]];
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<n;k++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
				mp[j][i]=mp[i][j];
			}
		}
	}
	for(int i=0;i<q;i++){
		int st,ed;cin>>st>>ed;
		int mi=1e17;
		for(int j=0;j<mpl[st].size();j++){
			for(int k=0;k<mpl[ed].size();k++){
				mi=min(mp[mpl[st][j]][mpl[ed][k]]+w[st]+w[ed]+dis[st][mpl[st][j]]+dis[ed][mpl[ed][k]],mi);
			}
		}
		cout<<mi<<endl;
	}return 0;
}
