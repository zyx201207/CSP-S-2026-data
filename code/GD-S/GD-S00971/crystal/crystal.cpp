#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,h=1,maxn=0,w,l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(1)
	{
		for(int i=1;i<=n-h;i++)
		{
			l=0;
			sum=0;
				sum++;
			for(int j=a[i];j<=a[i+h];j++)
			{
				l+=max(a[j+h],a[i])-min(a[j+1],a[i]);
			}
			if(maxn<=sum&&m>=l)
			{
				w=i;
				maxn=max(maxn,sum);
			}
		}
		h++;
		if(h=n)
		{
			break;
		}
	}
	cout<<w;
	return 0;
}

