#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int c,t;
int n,d;
int head[maxn];
int to[maxn*2];
int nex[maxn*2];
int weight[maxn*2];
int cnt=1;
int a[maxn];
vector<int>chang;
void build(int s,int e,int w){
	nex[cnt]=head[s];
	to[cnt]=e;
	weight[cnt]=w;
	head[s]=cnt;
	cnt++;
}
void dfs(int i,int e,int w){
	if(i==e){
		chang.push_back(w);
		return;
	}
	for(int ei=head[i];ei!=0;ei=nex[ei]){
		int v=to[ei];
		dfs(v,e,w+weight[ei]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		vector<int>a(n+10);
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			head[i]=0;
		}
		for(int len=1;len<=n;len++){
			for(int i=1;i+len<=n;i++){
				int j=i+len;
				if(abs(a[j]-a[i])<=d){
					build(i,j,abs(a[j]-a[i]));
//					cout<<a[i]<<" "<<a[j]<<'\n';
				}
			}
		}
//		cout<<chang.size()<<'\n';
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<chang.size()<<'\n';
				chang.clear();
				
				dfs(i,j,0);
				cout<<i<<"~"<<j<<":";
				for(int i=0;i<chang.size();i++){
					cout<<chang[i]<<" ";
				}
				cout<<'\n';
				sort(chang.begin(),chang.end());
				
				if((int)chang.size()>=2&&chang[0]==chang[1]){
					if(((int)chang.size()==2)||(chang.size()>=3&&chang[1]!=chang[2])){
						ans++;
						cout<<"гаЃК"<<i<<"~"<<j<<'\n';
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
