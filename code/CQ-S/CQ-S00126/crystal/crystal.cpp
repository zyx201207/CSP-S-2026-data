#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n, m, a[N];
int b[N], cnt;
int res, ans;
map<int, int>m1;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		if(a[i]!=a[i-1]) b[++cnt]=a[i];
		m1[a[i]]++;
	}
//	for(int i=1; i<=cnt; i++) cout<<b[i]<<" "<<m1[b[i]]<<endl;
	if(cnt<=8000 or n<=5100)
	{
		for(int i=1; i<=cnt; i++)
		{
			int m2=m;
			int num=0;
			for(int j=i; j<=cnt; j++)
			{
	//			cout<<b[j]-b[j-1]<<" "<<num<<" "<<j<<" "<<i<<" ";
	//			cout<<num+m1[b[j]]<<" "<<m2<<endl;
				
				int x=b[j]-b[j-1];
				if(j==i) x=0;	
//				if(i==66) cout<<j<<" "<<<<endl;
				if(x*num<=m2) m2-=x*num;	
				else
				{
//					cout<<num<<" "<<m1[b[j]]+num-m2/x<<endl;
					num=max(num, m1[b[j]]+m2/x);
					break;
				} 
				num+=m1[b[j]];
				
			}
//			cout<<cnt;
			ans=max(ans, num);	
//			if(ans==num) cout<<i;	
		}
	}
	else
	{
		int m2=m;
		int num=0;
		for(int j=1; j<=cnt; j++)
		{
			int x=b[j]-b[j-1];
			if(j==1) x=0;
			if(x*num<=m2) m2-=x*num;	
			else break;
			num+=m1[b[j]];
		}
		ans=num;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 
