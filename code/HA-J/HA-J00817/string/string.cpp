#include<bits/stdc++.h>
using namespace std;
int math[10000000];
char ch[10000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;int cnt=1;
	cin>>n;
	int al=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;al+=a;
		math[cnt]=a;
		ch[cnt]=b;
		cnt++;
	}
	cnt=n;
	long long ans=0;int l=1,r=cnt;
	for(l,r;l!=r;)
	{
		if(math[l]==math[r]&&ch[l]==ch[r])
		{
			l++;r--;
		}
		else if(math[l]!=math[r]&&ch[l]!=ch[r])
		{
			if(math[l]>math[r])
			{	
				ans+=math[r];
				math[l]=math[l]-math[r];r--;
			}
			else
			{	
				ans+=math[l];
				math[r]=math[r]-math[l];l++;
			}
		}
		else if(math[l]!=math[r]&&ch[l]==ch[r])
		{
			if(math[l]<math[r])
			{
				math[r]-=math[l];l++;
			}
			else if(math[l]>math[r])
			{
				math[l]-=math[r];r--;
			}
		}
		else if(math[l]==math[r]&&ch[l]!=ch[r])
		{
			ans+=math[l];l++;r--;
		}
		if(l>=r)
		{
			break;
		}
		
	}
	cout<<ans; 
	return 0;
}
