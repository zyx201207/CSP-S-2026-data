#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
const int N=2e5+5,mod=1e9+7;
int n;
int a[N],sum[N],suf[N];
char ch[N];
signed main(){
	File("string");
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i],sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]+a[i];
	int ans=0;
	for(int l=1,r=n,now=0;l<r;){
		int lst=now;now=min(sum[l],suf[r]);
		if(ch[l]!=ch[r])ans+=now-lst;
		if(sum[l]<suf[r])l++;
		else if(sum[l]>suf[r])r--;
		else l++,r--;
	}
	cout<<ans;
	return 0;
}