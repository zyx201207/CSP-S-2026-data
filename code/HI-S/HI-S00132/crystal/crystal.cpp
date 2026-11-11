#include<bits/stdc++.h>
using namespace std;
long long mid,a[500100],m,t,cz[500100],cnt,maxc=-1;
int n,f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
	}
	sort(a+1,a+n+1);
	if(f==0)
	{
		mid=a[n/2];
		for(int i=1;i<=n;i++)
		{
			cz[i]=abs(a[i]-mid);
		}
		sort(cz+1,cz+n+1);
		for(int i=1;i<=n;i++)
		{
			if(m<cz[i]) break;
			else cnt++,m-=cz[i];
		}
		cout<<cnt<<endl;
	}
	else{
		for(int i=2;i<=n;i++) a[i]-=a[1];
		a[1]-=a[1];
		for(int i=1;i<=n;i++)
		{
			t=m;
			int l=i-1, r=i+1;
			while(t)
			{
				if((l>=1&&r>n&&t<a[i]-a[l])||(l<1&&r<=n&&t<a[r]-a[i])||(l>=1&&r<=n&&t<min(a[i]-a[l],a[r]-a[i]))) break;
				else if((a[i]-a[l]<=a[r]-a[i]&&t>=a[i]-a[l]&&l>=1)||(l>=1&&r>=n&&t>=a[i]-a[l]))
				{
					t-=(a[i]-a[l]);
					l--;
					cnt++;
				}
				else if((a[i]-a[l]>a[r]-a[i]&&t>=a[r]-a[i]&&r<=n)||(l<1&&r<=n&&t>=a[r]-a[i]))
				{
					t-=(a[r]-a[i]);
					r++;
					cnt++;
				}
			}
			maxc=max(maxc,cnt+1);
			cnt=0;
		}
		cout<<maxc<<endl;
	}
	return 0;
} 
