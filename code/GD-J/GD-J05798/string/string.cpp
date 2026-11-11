#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ans=0,ls=0,lr=1,o;
char c[N],lx=' '; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		if(i>1&&c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			n--;
			i--;
		}
	}
	for(int i=1;;)
	{
		for(int j=n;j>i;)
		{
			if(ls==0)
			{
			if(c[i]!=c[j])
			{
				ans+=min(a[i],a[j]);
				if(a[i]==a[j]) i++,j--;
				ls=abs(a[i]-a[j]);
				if(a[i]>a[j]) lx=c[i],lr=1,j--;
				else if(a[j]>a[i]) lx=c[j],lr=2,i++;
			}
			else
			{
				lx=c[i];
				if(a[i]==a[j]) i++,j--;
				ls=abs(a[i]-a[j]); 
				if(a[i]>a[j]) lr=1,j--;
				else if(a[j]>a[i]) lr=2,i++;
			}	
			}
			else
			if(ls!=0)
			{
				if(lr==1)
				{
					if(lx!=c[j])
					{
						
						ans+=min(ls,a[j]);
						if(ls==a[j]) i++,j--;
						o=abs(ls-a[j]);
						if(ls>a[j]) lr=1,j--;
				        else if(a[j]>ls) lx=c[j],lr=2,i++;
						ls=o;
					}
					else
					{
						lx=c[i];
					    if(ls==a[j]) i++,j--;
						o=abs(ls-a[j]);
						if(ls>a[j]) lr=1,j--;
						else if(a[j]>ls) lr=2,i++;
						ls=o;
					}
				}
				else
				{
					if(c[i]!=lx)
					{
						ans+=min(a[i],ls);
						if(a[i]==ls) i++,j--;
						o=abs(ls-a[i]);
						if(a[i]>ls) lx=c[i],lr=1,j--;
				        else if(ls>a[i]) lr=2,i++;
						ls=o;
					}
					else
					{
						lx=c[i];
					    if(a[i]==ls) i++,j--;
						o=abs(ls-a[i]);
						if(a[i]>ls) lr=1,j--;
						else if(ls>a[i]) lr=2,i++;
						ls=o;
					}
				}
			}
		}
		break;
	}
	cout<<ans;
	return 0;
}
