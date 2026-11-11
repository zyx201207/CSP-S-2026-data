#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+5;
int c,t;
int n,k;
int a[N];
int cnt_e,hand[N*2],to[N*2],nxt[N*2];
void add(int u,int v){
	nxt[++cnt_e]=hand[u];
	to[cnt_e]=v;
	hand[u]=cnt_e;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}if(k==1){
			cout<<(n/2)<<"\n";
		}else{
			int f=0;
			if(k%2==0) f=1;
			n/=2;
			int ff=0;
			if(n%2==0) ff=1;
			if(ff==1){
				if(f==1){
					k-=2;
					int cnt=k/4;
					cout<<(n/2)-cnt<<"\n";
				}else{
					k-=3;
					int cnt=k/4;
					cout<<(n/2)-cnt<<"\n";
				}
			}else{
				if(f==1){
					k-=2;
					if(k%4==0){
						int cnt=k/4;
						cout<<(n/2)-cnt+1<<"\n";
					}else{
						int cnt=k/4;
						cout<<(n/2)-cnt<<"\n";
					}
				}else{
					k-=3;
					int cnt=k/4;
					cout<<(n/2)-cnt<<"\n";
				}
			}
		}			
		for(int i=0;i<=cnt_e;i++){
			to[i]=0;
			nxt[i]=0;
		}for(int i=0;i<=n;i++) hand[i]=0;
		cnt_e=0;
	}	
	return 0;
}
