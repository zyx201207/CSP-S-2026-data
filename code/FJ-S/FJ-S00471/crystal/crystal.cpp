#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[500005],c[500005],ans,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	ll k=s[2]-s[1],cnt=1,p=0;
	while(m>=k*cnt)
	{
		for(int i=1;i<=cnt;i++)s[i]+=k;
		cnt++;
		m-=k*cnt;
	}
	for(int i=1;i<=n;i++)if(s[i]==s[1])ans++;
	cout<<ans;
	return 0;
}
