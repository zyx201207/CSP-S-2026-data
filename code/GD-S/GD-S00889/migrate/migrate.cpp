#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=5e2+5;
int op,t;
ll n,d;
ll x[N],ans,cnt;
ll c[N],b[N]; 
struct node{
	int v;
	int w;
};
vector<node> E[N];
void check(int u,int v,ll ku){
	if(c[u]) return ;
	if(u==v){
		b[ku]++;
		return ;
	}	
	c[u]=1;
	for(int i=1;i<=n;i++){
		if(i!=u){
			if(abs(x[u]-x[i])<=d) check(i,v,ku+1);
		}
	}
	c[u]=0;
}
void solve(){
	ll p=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++) b[k]=0;
			check(i,j,0);
			for(int k=1;k<=n;k++){
				if(b[k]==1) break;
				if(b[k]==2){
					p++;
					break;
				}
			}
		}
	}
	cout<<p<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>op>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=300){
			solve();
		}
		
	}
	return 0;
}
