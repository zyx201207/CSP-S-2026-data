#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=500009,M=300009;
ll m,n,last[M],cnt[M],a,sec[N],res[N],fa[M],val[M];
bool ex[M];

ll find(ll a){
 if(fa[a]==a) return a;
 else{
 	ll f=fa[a];
 	fa[a]=find(fa[a]);
 	val[a]+=val[f];
 }
}

void uni(ll a,ll b,ll v){
	fa[a]=find(b);
	val[a]=v+val[b];
}


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	fa[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		sec[i]=a;
		cnt[a]++;
		last[a]=i;
		fa[a]=a;
	}
	uni(sec[n],0,cnt[sec[n]]);
	for(int i=n-1;i>0;i--){
		if(last[sec[i]]==i){
			uni(sec[i],sec[i+1],cnt[sec[i]]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<val[i]<<' ';
	}
	return 0;
}
