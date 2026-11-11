#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[200005];
string w[200005];
long long n,m;
int res[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		int tmp;
		cin >> tmp;
		a[i]=tmp;
		string s1;
		while(tmp!=0)
		{
			s1+=(tmp%2+'0');
			tmp/=2;
		}
		int tmp2=s1.size();
		for(int j=1; j<=tmp2; j++)
		{
			w[i]+=s1[s1.size()-j];
		}
	}
	sort(w+1,w+n+1);
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout << a[n];
		return 0; 
	}
	if(m==2)
	{
		int ans1=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i==j) continue;
				int tmp3=a[i]&a[j];
				if(tmp3>ans1) ans1=tmp3;
			}
		}
		cout << ans1;
		return 0;
	}
	//cout << w[1] << " " << w[2] << " " << w[3] << " " << w[4];
	int maxn=w[n].size();
	int res_t=1;
	for(int i=maxn-1; i>=0; i--)
	{
		for(int j=1; res_t<=m; j++)
		{
			if(w[n-j+1][i]=='1')
			{
				bool sit=1;
				for(int k=1; k<=res_t; k++)
				{
					if(n-j+1==res[k])
					{
						sit=0;
					}
				}
				if(sit)
				{
					res[res_t]=n-j+1;
					res_t++;
				}
			}
			else break;
		}
	}
	//cout << res_t << " ";
	//for(int i=1; i<res_t; i++)
	//{
	//	cout << res[i] << " ";
	//}
	long long ans=a[res[1]];
	for(int i=2; i<res_t; i++)
	{
		ans&=a[res[i]];
	}
	cout << ans;
	return 0;
}
