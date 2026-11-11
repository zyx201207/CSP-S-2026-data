#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
int high=0,r;
struct Node{
	int l[35];
} a[MAXN];

ll b[MAXN];
ll c[MAXN];
ll ans[35];
void chg(ll k,ll i){
	int j=0;
	while(k!=0){
		j++;
		a[i].l[j]=k%2;
		k/=2;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ÇåÁã 
	cin>>n>>m;
	r=n;
	for(ll i=1;i<=n;i++){
		cin>>b[i];
		chg(b[i],i);
	}

	for(int i=1;i<=32;i++){
		for(int j=1;j<=n;j++){
			c[i]+=a[j].l[i];
		}
	}
	

	for(int i=1;i<=32;i++){
		if(c[i]>=m) ans[i]=1,high=i;
		else{
			for(int j=1;j<=n;j++){
				a[j].l[i]=0;
			}
		}
	}
	int k=high;
	for(;high>=1;high--){
		if(ans[high]==0) continue;
		sort(a+1,a+r+1,[](const Node b,const Node c){
			return b.l[high]>c.l[high];
		});
		int tmpr=0;
		for(int i=1;i<=r;i++){
			if(a[i].l[high]==0) break;
			if(a[i].l[high]==1) tmpr=i;
		}
		if(tmpr>=m) r=tmpr;
	}
	for(int i=1;i<=k;i++) ans[i]=a[1].l[i];
	for(int i=1;i<=r;i++){
		for(int j=1;j<=k;j++){
			ans[j]&=a[i].l[j];
		}
	}
	
	
	ll aaas=0;
	for(int i=k;i>=1;i--){
		aaas*=2;
		aaas+=ans[i];
	}
	cout<<aaas;
	return 0;
}
