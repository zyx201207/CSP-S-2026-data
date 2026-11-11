//O(kdlogd+n^3+qd^2) 
#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int maxn=5e5+10,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
int n,m,d,q;
int w[maxn],k[maxn],d1[1010][1010];
int w1[1010][1010]; 
int a[maxn],t[maxn];
map<int,pair<int,vector<PII>>>mp; 
vector<pair<int,int>>l1[maxn],r1[maxn];
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(d1,0x3f,sizeof(d1));
	for(int i=1;i<=n;i++){ 
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			vector<PII>tmp=mp[a[j]].second;
			l1[a[j]].push_back({i,t[j]});
			r1[a[j]].push_back({i,t[j]});
			for(auto A:tmp){
				int t1=A.first,u=A.second;
				//u->Ïß£¬t1Ê±¼ä  
				d1[u][i]=min(d1[u][i],t1+t[j]);
				d1[i][u]=min(d1[i][u],t1+t[j]);
			}
			mp[a[j]].second.push_back({t[j],i});  
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d1[i][k]!=inf&&i!=j&&j!=k&&i!=k&&d1[k][j]!=inf){
					d1[i][j]=min(d1[i][j],d1[i][k]+d1[k][j]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(d1[i][j]!=inf)cout<<d1[i][j]<<' ';
//			else cout<<-1<<' ';
//		}
//		cout<<'\n';
//	} 
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=inf;
		//for(auto L:l1[l]){
		//	cout<<L<<' ';
		//}
		//for(auto R:r1[r]){
		//	cout<<R<<" ";
		//}
		//cout<<'\n';
		for(auto LL:l1[l]){
			for(auto RR:r1[r]){
				int L=LL.first,t1=LL.second;
				int R=RR.first,t2=RR.second;
				if(L!=R)ans=min(ans,d1[L][R]+t1+t2);
				else ans=t1+t2;
			}
		}
		//ans+=w[l]+w[r];
		//cout<<w[l]+w[r]<<' ';
		cout<<ans+w[l]+w[r]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1,c;
	//cin>>T;
	cin>>c;
	while(T--){
		solve();
	}
	return 0;
}
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++

