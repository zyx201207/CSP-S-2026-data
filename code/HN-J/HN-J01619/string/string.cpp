#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(c[l]==c[r]){
			int tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
			if(!a[l])++l;
			if(!a[r])--r;
		}else{
			int tmp=min(a[l],a[r]);
			ans+=tmp;
			a[l]-=tmp;
			a[r]-=tmp;
			if(!a[l])++l;
			if(!a[r])--r;
		}
	}
	cout<<ans;
	return 0;
}

