#include<iostream>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int head=0;
int s[N]={0};
int a[N];
int n,m;
int t[N]={0};
int ans[M]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=0;k<=n-1;k++)
	{
		
	
		for(int i=1+k;i<=n;i++) 
		{
			
			t[a[i]]++;
			if(t[a[i]]>1)
			{
				for(int j=i-1;j>=1;j--)
				{
					head--;
					t[s[j]]--;

				}
			}
			else
			{
				s[++head]=a[i];
			}
		}
		head=0;
		
		for(int i=1;i<=m;i++)
		{
			ans[i]+=t[i];
		    t[i]=0;
		}
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";

	return 0;
}
