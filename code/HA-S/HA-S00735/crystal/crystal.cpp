#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=1<<20;
long long n,m;
long long a[MAXN];
long long cnt[MAXN];
long long ans=0,l[MAXN];

void num(long long x,long long r){
	for(int i=1;i<=n;i++){
		if(a[i]==l[r]){
			continue;
		}
		if(a[i]<l[r]&&l[r]-a[i]<=m){
			x++;
			m=m-l[r]+a[i];
		}
		if(a[i]>l[r]&&a[i]-l[r]<=m){
			x++;
			m=m-a[i]+l[r];
		}
		if(m<=0){
			break;
		}
	}
	if(x<=n){
		ans=max(ans,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);

	for(long long i=1;i<=a[n];i++){
		if(ans<cnt[i]){
			ans=cnt[i];
			l[i]=i;
		}
	}
	
	for(int r=1;r<=a[n];r++){
		if(l[r]==0){
			continue;	
		}
		num(ans,r);
	}
	cout<<ans;
	return 0;
}
