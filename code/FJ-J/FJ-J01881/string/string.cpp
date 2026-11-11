#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char c[200010];
long long cnt=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	long long l=1,r=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	int L=1,R=n;
	while(l<r)
	{
		if(c[L] != c[R])
		{
			if(a[L] < a[R])
			{
				cnt+=a[L];
				l+=a[L];
				r-=a[L];
				a[R]-=a[L];
				L++;
			}
			else
			{
				cnt+=a[R];
				l+=a[R];
				r-=a[R];
				a[L]-=a[R];
				R--;
			}
		}
		else
		{
			if(a[L] < a[R])
			{
				l+=a[L];
				r-=a[L];
				a[R]-=a[L];
				L++;
			}
			else
			{
				l+=a[R];
				r-=a[R];
				a[L]-=a[R];
				R--;
			}
		}
	}
	cout<<cnt;
	return 0;//凑一下字节数，好记 11
}
