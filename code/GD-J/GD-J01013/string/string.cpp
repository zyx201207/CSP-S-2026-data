#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char x[200005];
bool f,r;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	scanf(" %c",&x[i]);
    	if(x[i]!=x[i-1]&&i!=1) f=1;
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	int i=1,j=n;
	while(i<=j)
	{
		if(i==j) break;
		else
		{
			ans+=max(a[i],a[j]);
			int e=max(a[i],a[j]);
			while(e>0&&i<=j)
			{
				int q;
				if(a[i]<a[j]) q=i+1;
				else q=j-1;
				if(a[q]>=e)
				{
					e=0;
					a[q]-=e;
				}
				else
				{
					e-=a[q];
					a[q]=0;
				}
				if(a[q]==0)
				{
					if(q==i+1) i=q+1;
					else j=q-1;
				}
			}
		}
		i++,j--;
	}
	cout<<ans;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
