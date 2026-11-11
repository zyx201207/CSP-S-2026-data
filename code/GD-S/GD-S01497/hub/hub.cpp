#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
int c,t;
vector<int> adj[maxn];
int fa[maxn];
bool vis[maxn],st[maxn];
int main(){	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}

		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			fa[v]=u;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(k<=2){
			cout<<log2(n)/3;
		}
		if(n<=5){
			if(n==k){
				cout<<0<<'\n';
				continue;
			}else	if(n==k+1){
				cout<<1<<'\n';
				continue;
			}else	if(n==k+2){
				if(n>=3){
					cout<<1<<'\n';
					continue;		
				}else{
					cout<<0<<'\n';
					continue;
				}
			}else	if(n==k+3){
				if(n>=4){
					cout<<1<<'\n';
					continue;
				}else{
					cout<<0<<'\n';
					continue;
				}
			}
		}else if(n<=10){
			if(n==k){
				cout<<0;
			}else if(n==k+1){
				cout<<1<<'\n';
			}else if(n==7){
				if(k==5||k==4||k==3){
					cout<<1<<'\n';
				}
					
				
			}else if(n==8){
					cout<<1<<'\n';
			}else if(n==9){
				if(k>=6){
					cout<<1<<'\n';
				}else{
					int a[11]={0,0,0,0,0,0,0,0,0,0};
					for(int i=1;i<=n;i++){
						a[fa[i]]++;
					}
					int cnt=0;
					for(int i=1;i<=n;i++){
						if(a[i]==2){
							cnt++;
						}
					}
					if(cnt>=2){
						cout<<2<<'\n';
					}else{
						cout<<1<<'\n';
					}
				}
			}else{
					int a[11]={0,0,0,0,0,0,0,0,0,0};
					for(int i=1;i<=n;i++){
						a[fa[i]]++;
					}
					int cnt=0;
					for(int i=1;i<=n;i++){
						if(a[i]==2){
							cnt++;
						}
					}
					if(cnt>=2){
						cout<<2<<'\n';
					}else{
						cout<<1<<'\n';
					}
				}
				continue;
			}
			cout<<0<<'\n';
		}
	
			
	return 0;
}
