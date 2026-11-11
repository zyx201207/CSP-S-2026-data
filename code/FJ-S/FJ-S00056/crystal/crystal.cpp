#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct Node{
	long long num,v;
}a[500005];
long long ans;
long long a2[500002];
long long cha[500002];
long long cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a2[i];
	}
	sort(a2+1,a2+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a2[i]!=a2[i-1])
		{
			a[++cnt].v=a2[i];
			a[cnt].num=1;
		}else{
			a[cnt].num++;
		}
	}
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<a[i].v<<" "<<a[i].num<<endl;
//	}
	for(int i=2;i<=cnt;i++)
	{
		cha[i]=a[i].v-a[i-1].v;
	}
	for(int i=1;i<=cnt;i++)
	{
		long long x=m;
		long long k=0;
		long long jian=0;
		for(int j=i-1;j;j--)
		{
			jian=jian+cha[j+1];
			if(x>=jian*a[j].num)
			{
				x-=jian*a[j].num;
				k+=a[j].num;
			}else{
				k+=x/jian;
				break;
			}
		}
		ans=max(ans,k+a[i].num);
	}
	cout<<ans;
}
