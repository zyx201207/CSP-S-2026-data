#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char ch[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	while(l<r){
		int len=min(a[l],a[r]);
		if(ch[l]!=ch[r])ans+=len;
		a[l]-=len,a[r]-=len;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	if(a[l]!=a[r])ans+=(a[l]+a[r])/2;
	cout<<ans;
	return 0;
}
