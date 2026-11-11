#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,ans,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,r=n-1;
	for(int i=0;i<n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			l++,r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l],l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r],r--;
		}
	}cout<<ans;
}
