#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,jl=0,jl2=0;
	while (l<=r){
		if (c[l]==c[r]){
			if (a[l]-jl>a[r]-jl2){
				 jl+=a[r];
				 jl2=0;
				 r--;
			}else if (a[l]-jl<a[r]-jl2){
				 jl2+=a[l];
				 jl=0;
				 l++;
			}else{
				 jl=0;
				 jl2=0;
				 l++;
				 r--;
			}
		}else{
			if (a[l]-jl>a[r]-jl2){
				ans+=a[r]-jl2;
				jl2=0;
				jl+=a[r];
				r--;
			}else if (a[l]-jl<a[r]-jl2){
				ans+=a[l]-jl;
				jl=0;
				jl2+=a[l];
				l++;
			}else{
				ans+=a[r]-jl2;
				jl=0;
				jl2=0;
				l++;
				r--;
			}
				
		}
	}
	cout<<ans;
	return 0;
}