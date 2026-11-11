#include <bits/stdc++.h>
using namespace std;

long long n,m,a[514514],max_ans,s[514514];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int min_in_a=a[1];
	for (int i=1;i<=n;i++)
	{
		a[i]-=min_in_a;
		//cout << a[i] << ' ';
	}
	//cout << endl;
	for (int i=1;i<=n;i++)
	{
		//s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		s[i]=s[i-1]+a[i];
	}
	/*for (int i=1;i<=n;i++)
	{
		cout << s[i] << ' ';
	}*/
	for (int i=1;i<=n;i++)
	{
		long long cnt=0;
		long long L=1,R=i,mid;
		while (L<R)
		{
			mid=(L+R)/2;
			//cout << i << ' ' << L << ' ' << R << ' ' << a[i]*(i-1)-s[mid] << endl;
			//cout << i << ' ' << L << ' ' << R << ' ' << a[i] << ' ' << (i-mid) << ' ' << a[i]*(i-mid)-(s[i]-s[mid]) << endl;
			if (a[i]*(i-mid)-(s[i-1]-s[mid-1])>m)
			{
				L=mid+1;
			}else{
				R=mid;
			}
		}
		//cout << "end L=" << L << endl;
		max_ans=max(max_ans,i-L+1);
	}
	cout << max_ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
