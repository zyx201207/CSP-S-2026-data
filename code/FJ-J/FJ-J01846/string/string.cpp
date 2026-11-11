#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,r,l,a_MIN;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	r=n,l=1;
	while(r>l){
		a_MIN=min(a[r],a[l]);
		if(c[r]!=c[l])ans+=a_MIN;
		a[r]-=a_MIN;
		a[l]-=a_MIN;
		if(a[r]==0)r--;
		if(a[l]==0)l++;
	}
	cout<<ans;
	return 0;
}
