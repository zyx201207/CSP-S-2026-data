#include<bits/stdc++.h>
using namespace std;
long int n,m,ans=0,cnt=0,a1,a[5000005],b[5000005],c[5000005];
bool cmp(long int x,long int y)
{
	return x>y;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(long int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long j=0,r=0;
	for(long int i=1;i<=n;i++)
	{
		if(b[j]!=a[i]){
			j++;
			b[j]=a[i];
			r--;
		}
		r++;
		c[j]++;
	}
	/*for(int i=1;i<=n-r;i++)
	{
		cout<<b[i]<<" "<<c[i]<<" ";
	}*/
	for(int i=1;i<=n-r;i++)
	{	
		long int m1=m;
		cnt=c[i];
		for(int j=i+1;j<=n-r;j++)
		{
			int long s=(b[j]*c[j])+m1; 
			if(s<b[i]*c[j]){
				cnt+=(m1)/(b[i]-b[j]);
				break;
			}
			//if(i==20)cout<<"["<<j<<"]"<<b[j]<<"//"<<c[j]<<"["<<m1<<"]; ";
			if(s>=b[i]*c[j]) 
			{
				m1-=(b[i]-b[j])*c[j];
				cnt+=c[j];
			}
		}
		ans=max(ans,cnt);
		//if(cnt=314618) cout<<i<<" ";
		if(ans>=n-i+1) break;
	}
	printf("%d",ans);
}
