#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005];
char c[200005];
ll cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	cnt>>=1;
	int l=1,r=n;
	while(cnt>0&&l<r){
		if(a[l]>=a[r]){
			cnt-=a[r];a[l]-=a[r];
			if(c[l]!=c[r]) ans+=a[r];
			--r;
		}else{
			cnt-=a[l];a[r]-=a[l];
			if(c[l]!=c[r]) ans+=a[l];
			++l;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
