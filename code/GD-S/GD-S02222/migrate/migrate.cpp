#include <bits/stdc++.h>
using namespace std;
long long a[2000006];
long long b[2000006];
vector<long long>c[2000006];
long long d[2000006];
long long e[2000006];
long long f[2000006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,t;
	cin>>cc>>t;
	while(t--)
	{
		int n;
		long long x;
		cin>>n>>x;
		int sum = 0;
		b[0] = 1;
		e[0]=0;
		for(int i = 1; i <= n; i++ )
		{
			cin>>a[i];
			b[i]=0;
			c[i].clear();
			d[i]=0;
			f[i]=0;
		}
		a[0]=a[1]-x;
		int now = 1;
		int las = 0;
		for(int i = 1; i <= n; i++ )
		{
			while(now<n&&a[now+1]-a[i]<=x)
			{
				now++;
			}
//			f[i]++;
			while(a[i]-a[las]>x)
			{
				las++;
			}
			b[i] = now;
			e[i] = las;
//			cout<<"  "<<e[i-1]<<" "<<las<<endl;
//			for(int j = e[i-1]+1; j <= e[i]; j++ )
//			{
//				f[i]+=f[j];
//			}
			f[now]+=f[i]+1;
//			cout<<"               f "<<f[i]<<endl;
			if(now!=i)
			{
				c[now].push_back(i);
			}
//			cout<<i<<" "<<now<<endl;
			
//			cout<<"                "<<i<<" "<<c[i].size()<<endl;
			if(c[i].size()>1)
			{
				d[i]+=f[c[i][1]];
				
//				cout<<"                                     "<<i<<" "<<f[c[i][1]]<<" "<<c[i][1]<<endl;
			}
			sum+=d[i];
			if(c[i].size()<=1&&las+1<i) 
			{
				sum+=f[las+1];
//				sum+=d[las+1];
//				cout<<"  "<<las<<" "<<i<<" "<<c[las+1].size()<<endl;
			}
			for(int j = b[i-1]+1; j <= b[i]; j++)
			{
				d[j]+=d[i];
//				cout<<"                   "<<i<<" "<<j<<endl;
			}
//			cout<<i<<" "<<sum<<" "<<d[i]<<" "<<c[i].size()<<endl;
		}
		cout<<sum<<endl;
	}
}
/*
1 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

*/
