#include<bits/stdc++.h>
using namespace std;
const int NUM=2e6+10;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;

int n,d;
int a[NUM],b[NUM];

int sol(int x){
	b[x]=0;
	for(int i=x+1,j=x;i<=n;i++){
		while(a[j]+d<a[i]) j++;
		b[i]=b[j]+1;
	}
	int ans=0;
	for(int i=x+1,l=x,r=x+1;i<=n;++i){
		while(b[l]<b[i]-1) l++;
		while(b[r]<b[i]) r++;
		l=max(l,i-d);
		ans+=(r-l==2);
	}
	return ans;
}

void work(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];b[i]=inf;
	}
	a[n+1]=inf;
	int ans=0;
	for(int i=1;i<=n;++i) ans+=sol(i);
	cout<<ans<<'\n';
}

int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) work();
	return 0;
}
