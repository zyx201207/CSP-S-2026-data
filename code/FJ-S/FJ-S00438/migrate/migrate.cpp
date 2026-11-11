#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e6+5;

int c,t,n;
ll d;
ll x[MAXN];
int jl[MAXN],jr[MAXN];

void f(){
	for (int i=1,l,r,mid;i<=n;i++){
		jl[i]=i,l=1,r=i;
		while (l<=r){
			mid=(l+r)>>1;
			if (x[i]-x[mid]>d) l=mid+1;
			else r=mid-1,jl[i]=mid;
		}
		
		jr[i]=i,l=i,r=n,mid;
		while (l<=r){
			mid=(l+r)>>1;
			if (x[mid]-x[i]>d) r=mid-1;
			else l=mid+1,jr[i]=mid;
		}
	}
}

void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;i++)
		cin>>x[i];
		
	f();
	
	int ans=0;
	for (int i=1;i<=n;i++){
		if (jr[i]==i||jr[i]==i+1) continue;
		ans+=(jl[jr[jr[i]-1]]==jr[i]-1
				&&jl[jr[i]]==i);
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	while (t--)
		solve();
	
	return 0;
}
