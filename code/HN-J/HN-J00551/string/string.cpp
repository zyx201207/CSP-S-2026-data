#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char s;
int cnt[26];
int ans=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (inr i=1;i<=n;i++)
	{
		cin>>a>>s;
		cnt[s-'a'+1]++;	
	}
	if (n==1)cout<<0;
//	sort(cnt+1,cnt+1+n,cmp);
	if (n==2)
	{
		int flag=0;
		for (int i=1;i<=26;i++)
		{
			if(cnt[i]==2)
			{
				flag=1;
				cout<<0;
				break;
			}
		}
		if (!flag)cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
