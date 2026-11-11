#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int INF=0x3f3f3f3f,P=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
int n;
ll m;
ll a[N],d[N];
ll s1[N],s2[N];

bool chk(int x){
	for(int l=1,r=x;r<=n;++l,++r){
		if(s1[r]-s1[l]-(s2[r]-s2[l])*l<=m) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		d[i]=a[i]-a[i-1];
		s1[i]=s1[i-1]+d[i]*i;
		s2[i]=s2[i-1]+d[i];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<"\n";
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
