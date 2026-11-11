//GZ-J00514 ÑîµÂÓî
#include<bits/stdc++.h>
using namespace std;
int n,l,r,a[201011];
long long len,ans;
char c[201011];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],len+=a[i];
	l=1; r=n;
	for(;l<=r;){
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			if(a[r]==0) r--;
			if(a[l]==0) l++;
		}
		else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
			if(a[r]==0) r--;
			if(a[l]==0) l++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
