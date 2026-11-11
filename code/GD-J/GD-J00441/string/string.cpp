#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int a[int(2e5+5)];
char c[int(2e5+5)];
int32_t main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0,huanc=0;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			huanc=max(a[l],a[r])-min(a[l],a[r]);
			if(a[l]<a[r])l++,a[r]-=huanc;
			else if(a[r]<a[l])r--,a[l]-=huanc;
			else l++,r--;
		}else{
			huanc=max(a[l],a[r])-min(a[l],a[r]);
			if(a[l]<a[r])l++,a[r]-=huanc;
			else if(a[r]<a[l])r--,a[l]-=huanc;
			else l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
