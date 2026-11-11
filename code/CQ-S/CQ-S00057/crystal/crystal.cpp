#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500050],k[500500],m,sum[500500];
signed main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		k[i]+=a[i]-a[i-1],sum[i]=sum[i-1]+k[i];
	int ans=-1;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if((k[j]-k[i-1])<=m)
//				ans=max(j-i+1,ans);
	int cnt=0;
	for(int i=1,j=1;j<=n;)
	{
		if(cnt<=m)
			cnt=cnt+(j-i+1)*k[j++];
		else
			cnt=cnt-k[i]-sum[j]+sum[i++];
		ans=max(j-i,ans);
	}
	cout << ans;	
}/*
Schicksal glaube ich nicht,und ich glaube nur meine Augen und Ohren.
Deshalb scheisst CCF verdammt,und mag Kot am liebsten essen.Ich moechte deine Mutter ficken; 
*/
