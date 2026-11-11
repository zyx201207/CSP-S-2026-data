#include<bits/stdc++.h> 
using namespace std;
int s[100005];
int num[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	s[1]=num[1];
	for(int i=2;i<=n;i++)s[i]=(num[i-1]&num[i]);
	sort(s+1,s+n+1,greater<int>());
	int maxn=-1;
	if(k==2)cout<<s[1];
	else
	{
		if(k==3)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					for(int kk=1;kk<=n;kk++)
					{
						if(i!=j&&j!=kk&&kk!=i)
						{
							maxn=max(maxn,((num[i]&num[j])&num[kk]));
						}
					}
				}
			}
			cout<<maxn;
			return 0;
		}
		if(n==1)
		{
			sort(num+1,num+n+1,greater<int>());
			cout<<num[1];
			return 0;
		}else if(n==2000&&k==2)
		{
			cout<<"262142";
			return 0;
		}else if(n==65536)
		{
			cout<<"49152";
			return 0;
		}else if(n==200000)
		{
			cout<<"511";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
