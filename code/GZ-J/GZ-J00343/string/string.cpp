//GZ-J00343 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int l=1,r=n;l<r;){
		if(c[l]!=c[r]){
			long long mi=min(a[l],a[r]);
			ans+=mi;
			a[l]-=mi,a[r]-=mi;
			if(a[l]==0) l++;
			else r--;
		}
		else{
			long long mi=min(a[l],a[r]);
			a[l]-=mi,a[r]-=mi;
			if(a[l]==0) l++;
			else r--;
		}
	}
	cout<<ans;
	return 0;
}
