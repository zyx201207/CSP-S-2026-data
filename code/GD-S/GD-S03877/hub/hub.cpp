#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define RFOR(i,j,k) for(ll i=j;i>k;i--)
#define ll long long

int c,T,n,k,v[17],hd[17],e=0,inu,inv,cnt1,cnt2;
bool f[17];
struct edge{
	int nxt,to;
}edg[27];
void add(int u,int v){
	edg[e].to=v;
	edg[e].nxt=hd[u];
	hd[u]=e;
	e++;
}
int fd(int a){
	if(v[a]!=a){
		v[a]=fd(v[a]);
	}
	return v[a];
}
int dfs1(int x,int pa,int cnt1){
	if(f[x])return cnt1;
	int tans=100;
	for(int i=hd[x];i!=-1;i=edg[i].nxt){
		if(pa==edg[i].to)continue;
		tans=min(tans,dfs1(edg[i].to,x,cnt1+1));
	}
//	if(T==1)cout<<x<<' '<<tans<<" q2121\n"; 
	return tans;
} 
ll ans1,tans;
void uni(int a,int b){
	int ast,bst;
	ast=fd(a);
	bst=fd(b);
	if(ast!=bst){
		cnt1--;
		v[ast]=bst;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c<=3){
		while(T--){
			memset(hd,-1,sizeof(hd));
			e=0;
			cin>>n>>k;
			FOR(i,1,n){
				cin>>inu>>inv;
				add(inu,inv);
				add(inv,inu);
			}
			ans1=1000000;
			FOR(i,0,(1<<n)){
//				cout<<i<<' '<<(1<<n)<<" q22\n";
				cnt1=0;
				cnt2=0;
				tans=0;
				FOR(j,0,n){
					v[j]=j;
					f[j+1]=0;
				}
//				cout<<" don1\n";
				FOR(j,0,n){
					if(i&(1<<j)){
						cnt1++;
						cnt2++;
						f[j+1]=1;
						for(int k=hd[j+1];k!=-1;k=edg[k].nxt){
//							cout<<k<<" q22\n";
							if(i&(1<<(edg[k].to-1))){
								uni(j,edg[k].to-1);
							}
						}
					}
				}
//				cout<<i<<' '<<cnt1<<' '<<cnt2<<" qans\n";
				if(cnt1<=2&&cnt2==k){
//					cout<<" q44\n";
					FOR(j,0,n){
						tans=max(tans,(ll) dfs1(j+1,0,0));
//						if(T==1)cout<<j+1<<' '<<"\n\n";
					}
//					if(T==1)cout<<tans<<' '<<i<<" q22\n"; 
					ans1=min(ans1,tans);
				}
				
			}
			cout<<ans1<<endl;
		}
	}else if(c>=13&&c<=14){
		while(T--){
			cin>>n>>k;
			FOR(i,1,n){
				cin>>inu>>inv;
			}
			if(k==1){
				cout<<n/2+1<<endl;
			}else if(k<n/2){
				cout<<(n/2-k)/4+((n/2-k)%4!=0)+1<<endl;
			}else if(k<n){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	
	return 0;
} 
