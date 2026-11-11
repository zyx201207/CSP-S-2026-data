#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],s[N],tp,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	tp=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	for(int k=31;k>=1;k--){
		int res=0;
		for(int i=1;i<=tp;i++){
			if((s[i]>>(k-1))&1){
				res++;
			}
		} 
		if(res<m){
			continue;
		}
		ans+=(1<<(k-1));
		int l=0;
		for(int i=1;i<=tp;i++){
			if((s[i]>>(k-1))&1){
				s[++l]=s[i];
			}
		}
		tp=l;
	}
	cout<<ans;
	return 0;
}
