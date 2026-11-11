#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int er_2[N];
int er[N];
int a[N];
int max_n=0;
int idx=0;
int idx2=0;
int cmp(int s)
{
	int cnt=0;
	for(int k=1;k<=s;k++)
	{
		if(er_2[k]==er[k])
		{
			if(er[k]==1)
			{
				er_2[k]=1;
			}
			else
			{
				er_2[k]=0;
			}
		}
		else
		{
			er_2[k]=0;
		}
	}
}
void f(int l)
{
	while(l!=0)
	{
		idx++;
		er[idx]=l%2;
		l/=2;
	}
	return;
}
void f2(int l)
{
	while(l!=0)
	{
		idx2++;
		er_2[idx]=l%2;
		l/=2;
	}
	return;
}
int fan(int s)
{
	int cnt=0;
	int qq=1;
	for(int k=1;k<=s;k++)
	{
		cnt+=qq*er_2[k];
		qq*=2;
	}
	return cnt;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f(a[i]);
		if(i==1)
		{
			for(int j=1;j<=idx;j++){
				er_2[j]=er[j];
			}
			idx2=idx;
		}
		else
		{
			idx2=max(idx,idx2);
			cmp(idx2);
		}
		max_n=max(max_n,a[i]);
		idx=0;
	}
		int max_n2=0;
	if(m==1)
	{
		cout<<max_n;
	}
	else if(m==n)
	{
		cout<<fan(idx2);
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				idx=0;
				f(a[i]);
				idx2=0;
				f2(a[j]);
				cmp(max(idx,idx2));
				int cnt=fan(max(idx,idx2));
				max_n2=max(max_n2,cnt);
			}
		}
		cout<<max_n2;
	}
	return 0;
}
