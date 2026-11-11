#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m,maxn=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				int te1=a[i],te2=a[j],tb=1,sum=0;
				while(te1!=0&&te2!=0)
				{
					if((te1%2==1&&te2%2==1))
					{
						sum+=tb;		
						//cout<<sum<<endl;
					}
					    te1/=2,te2/=2;
						tb*=2;
					
				}
				
				//cout<<a[i]<<" "<<a[j]<<" "<<sum<<endl;
				maxn=max(maxn,sum);
			}
	}
	cout<<maxn<<endl;
	return 0;
}
