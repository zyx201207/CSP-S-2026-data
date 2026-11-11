#include <bits/stdc++.h>
using namespace std;

long long a[27],cnt[27],mid;
int n,k;
char zi,zifu;
short ji=0;

long long huiwen(short ji)
{
	if(ji == 0)
		return abs(cnt[26]-a[1]);
	else
		return abs(cnt[26]-a[1])+1;
}

/*long long huiwen(long long mid,char zifu)
{
	if(zifu < 13)
		return mid;
	else
	{
		mid/=2;
		huiwen(mid,zifu);
	}
}*/

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin >> k >> zi;
		a[zi-'a']+=k;
		ji=(ji+k)%2;
		cnt[i]=cnt[i-1]+a[i];
	}
	
	mid = cnt[26]/2;
	
	for(int i=1;i<=26;i++)
	{
		if(mid-a[i] > 0)
			continue;
		zifu = i-1 ;
	}
	
	cout << huiwen(ji);
	/*huiwen(mid,zifu);
	cout << cnt[26]-mid;*/

	return 0;
} 
