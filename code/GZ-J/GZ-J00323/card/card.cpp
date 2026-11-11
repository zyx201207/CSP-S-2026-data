//GZ-J00323 遵义航天实验中学 杨熙晨 
#include<bits/stdc++.h>
using namespace std;
int n,m,card[500005],ans[300005],top=0,s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			int tf=0;
			for(int k=1;k<=top;k++)
			{
				if(s[k]==card[j])
				{
					top=k;
					tf=1;
					break;
				}
			}
			if(!tf)
			{
			top++;
			s[top]=card[j];
			}
		}
		for(int j=1;j<=top;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(s[j]==k)
				{
					ans[k]++;
					break;
				}
			}
		}
		for(int p=1;p<=top;p++) cout<<s[p]<<' ';
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
