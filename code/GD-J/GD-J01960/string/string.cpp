#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200009],s[200009];
char c[200009];
int l = 1,r,ans;
int pos(int x){
	int L = 1,R = n;
	while(L<R){
		int mid = (L+R)/2;
		if(s[mid]>=x){
			R = mid;
		}else L = mid+1;
//		cout<<x<<" "<<mid<<'\n';
	}
	return R;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i){
		cin>>a[i]>>c[i];
		s[i] = s[i-1]+a[i];
		r+=a[i];
	}
	while(l<r){
		int dl = pos(l),dr = pos(r);
		int mat = min(s[dl]-l+1,r-s[dr-1]);
		if(c[dl]!=c[dr]){
			ans+=mat;
		}
		l+=mat,r-=mat;
	}
	cout<<ans;
}
