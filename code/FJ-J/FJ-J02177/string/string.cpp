#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int n,a[N];
long long ans,sum,res;
char c[N];
char s;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];cin>>c[i];
	}
	int i=1,j=n;
	while(i<=j)
	{
		if(s!=c[j]&&res==1&&ans<=a[j])
		{
			sum+=ans;
			a[j]-=ans;
			ans=0;
		}
		else if(s!=c[j]&&res==1&&ans>a[j])
		{
			sum+=a[j];
			ans-=a[j];
			a[j]=0;
		}
		else if(s!=c[i]&&res==0&&ans<=a[i])
		{
			sum+=ans;
			a[i]-=ans;
			ans=0;
		}
		else if(s!=c[i]&&res==0&&ans>a[i])
		{
			sum+=a[i];
			ans-=a[i];
			a[i]=0;
		}
		else if(s==c[j]&&res==1&&ans<=a[j])
		{
			a[j]-=ans;
			ans=0;
		}
		else if(s==c[j]&&res==1&&ans>a[j])
		{
			ans-=a[j];
			a[j]=0;
		}
		else if(ans!=0&&s==c[i]&&res==0&&ans<=a[i])
		{
			a[i]-=ans;
			ans=0;
		}
		else if(ans!=0&&s==c[i]&&res==0&&ans>=a[i])
		{
			ans-=a[i];
			a[i]=0;
		}
		if(a[i]>a[j]&&c[i]!=c[j]&&a[j]>=0)
		{
			res=1;
			sum+=a[j];
			ans+=a[i]-a[j];
			a[i]-=a[j];
			a[j]=0;
			s=c[i];
		}
		else if(a[i]>a[j]&&c[i]==c[j]&&a[j]>=0)
		{
			ans+=a[i]-a[j];
			a[i]-=a[j];
			a[j]=0;
			s=c[i];
			res=1;
		}
		else if(a[i]<a[j]&&c[i]!=c[j]&&a[i]>=0)
		{
			sum+=a[i];
			ans+=a[j]-a[i];
			a[j]-=a[i];			
			a[i]=0;
			s=c[j];
			res=0;
		}
		else if(a[i]<a[j]&&c[i]==c[j]&&a[i]>=0)
		{
			ans+=a[j]-a[i];
			a[j]-=a[i];
			a[i]=0;
			s=c[j];
			res=0;
		}
		else if(a[i]==a[j]&&c[i]!=c[j]&&a[i]>=0)
		{
			sum+=a[i];
			a[i]=0;
			a[j]=0;
		}
		j--;
		i++;
	}
	cout<<sum;
	return 0;
}
