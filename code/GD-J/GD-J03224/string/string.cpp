#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,ans,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];l++;
		}else{
			if(c[l]!=c[r])ans+=a[r];
			if(a[l]==a[r])l++,r--;
			else a[l]-=a[r],r--;
		}
	}
	cout<<ans;
	return 0;
}
