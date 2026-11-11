#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e5+10;
ll len[Maxn];
char c[Maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if(n==1)
	{
		cout << 0;
		return 0;	
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		cin >> len[i] >> c[i];
		sum+=len[i];
	}
	ll left=sum/2;
	ll dq=0;
	ll L, R;
	for(int i=1;i<=n;i++)
	{
		if(dq+len[i]==left)
		{
			L=i, R=i+1;
			if(sum%2==1)
			{
				len[i+1]--;
			}
			break;
		}
		if(dq+len[i]==left+1 && sum%2==1)
		{
			L=i, R=i+1;
			len[i]--;
			break;
		}
		if(dq+len[i]>left)
		{
			ll zuo=left-dq;
			ll you=len[i]-zuo-(sum%2);
			for(int j=n;j>i;j--)
			{
				len[j+1]=len[j];
				c[j+1]=c[j];
			}
			L=i, R=i+1;
			len[i]=zuo;
			len[i+1]=you;
			c[i+1]=c[i];
			n++;
			break;
		}
		dq+=len[i];
	}
	// cout << L << " " << R << "\n";
	// for(int i=1;i<=n;i++)
	// {
	// 	cout << len[i] << " " << c[i] << "\n";
	// }
	ll lsum=0, rsum=0;
	ll ans=0;
	L++, R--;
	while(L>1 || R<n)
	{
		while(lsum==rsum && L>1 && R<n)
		{
			lsum+=len[--L];
			rsum+=len[++R];
			if(c[L]!=c[R])
			{
				ans+=min(len[L],len[R]);
			}
		}
		while(lsum>rsum && R<n)
		{
			ll cur=min(len[R+1],lsum-rsum);
			rsum+=len[++R];
			ans+=(c[L]!=c[R])*cur;
		}
		while(lsum<rsum && L>1)
		{
			ll cur=min(len[L-1],rsum-lsum);
			lsum+=len[--L];
			ans+=(c[L]!=c[R])*cur;
		}
	}
	cout << ans;
	return 0;
}