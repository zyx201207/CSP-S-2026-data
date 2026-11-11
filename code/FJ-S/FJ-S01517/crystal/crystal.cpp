#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[1000001],cf[1000001],t=0,lastmember=1;
long long read()
{
	int base=1;
	long long res=0;
	char ch=getchar();
	while(!(('0' <= ch&&ch <= '9')||ch == '-'))
	{
		ch=getchar();
	}
	if(ch == '-') 
	{
		base=-1;
		ch=getchar();
	}
	while('0' <= ch&&ch <= '9')
	{
		res*=10;
		res += ch-'0';
		ch=getchar();
	}
	res *= base;
	return res;
}
int check(int k)
{
	int num=k-lastmember+1;
	t += cf[k]*(k-lastmember);
	//cout <<lastmember<<"-"<< k << "  " << t << endl;
	if(t > m)
	{
		while(t > m)
		{
			t -= a[k]-a[lastmember];
			lastmember++;
		}
		num=k-lastmember+1;
		//cout <<"tiao:"<<lastmember<<"-"<< k << "  " << t << endl;
	}
	return num;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m; 
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cf[i]=a[i]-a[i-1];
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int cnt=check(i);
		//cout << cnt << endl;
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}