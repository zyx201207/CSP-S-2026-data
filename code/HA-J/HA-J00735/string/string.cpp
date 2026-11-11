#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
int ed[200005],st[200005],ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int dc=n,sp,ep;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		ed[i]=a[i]+ed[i-1];
		st[i]=ed[i-1]+1;
	}
	int l=ed[n],mid=(ed[n]+1)/2;
	for(int i=1;i<=n;++i){
		if(st[i]>=mid)break;
		sp=l+1-ed[i];
		ep=l+1-st[i];
		while(1){
			if(c[dc]!=c[i])ans+=min(ep,ed[dc])-max(sp,st[dc])+1;
			if(sp<st[dc])--dc;
			else break;
		}
	}
	cout<<ans;
	return 0;
}
