#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long to[520][520];
vector<pair<int,long long> > dwy[510000];
long long sw[510000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<520;i++){
		for(int j=0;j<520;j++){
			to[i][j]=1e18+10;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>sw[i];
	} 
	for(int i=1;i<=n;i++){
		int jn;
		cin>>jn;
		for(int j=1;j<=jn;j++){
			int v;
			long long w;
			cin>>v>>w;
			dwy[v].push_back(make_pair(i,w));
		}
		
	}
	for(int i=1;i<=n;i++){
		to[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<dwy[i].size();j++){
			for(int j2=j+1;j2<dwy[i].size();j2++){
//				cout<<j<<" "<<j2<<"\n";
//				cout<<dwy[i][j].first<<" "<<dwy[i][j2].first<<"\n";
				 to[dwy[i][j].first][dwy[i][j2].first]=to[dwy[i][j2].first][dwy[i][j].first]=min(dwy[i][j].second+dwy[i][j2].second,to[dwy[i][j2].first][dwy[i][j].first]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(k==i||k==j)continue;
				if(to[i][k]+to[k][j]<to[i][j]){
					to[i][j]=to[j][i]=to[i][k]+to[k][j];
				}
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<to[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		long long ans=2e18;
		for(auto it1:dwy[s]){
			for(auto it2:dwy[t]){
				if(it1.second+it2.second+to[it1.first][it2.first]<ans){
					ans=it1.second+it2.second+to[it1.first][it2.first]; 
				}
			}
		}
		cout<<sw[s]+sw[t]+ans<<"\n"; 
	} 
	return 0;
}
