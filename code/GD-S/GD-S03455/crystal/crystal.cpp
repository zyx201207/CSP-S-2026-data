#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],js,ans;
long long res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1; j<=n; j++)
	{
		js++;
		res+=a[j];
		long long len=j-i+1;
		long long cnt=len*a[j];
		cnt-=res;
		if(cnt>m)
		{
			while(i<=n)
			{
				len--;
				js--;
				res-=a[i];
				cnt=len*a[j];
				i++;
				cnt-=res;
				if(cnt<=m) break;
			}
		}
		ans=max(js,ans);
	}
	cout<<ans;
	return 0;
}
