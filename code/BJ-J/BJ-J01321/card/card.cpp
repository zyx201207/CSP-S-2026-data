#include<bits/stdc++.h>
using namespace std;
int n,m,ans[100001]={0},a[100001],ty[100001],fl=-1;
stack<int>b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ty[a[i]]++;
		fl=max(fl,a[i]);
	}
	for(int i=0;i<n;i++)
	{
		int t[100001]={0};
		for(int j=i;j<n;j++)
		{
			
			t[a[j]]++;
			if(t[a[j]]>1)
			{
				while(b.top()!=a[j])
				{
					b.pop();
				}
				b.pop();
				t[a[j]]=1;
			}
			b.push(a[j]);
		}
		while(!b.empty())
		{
			ans[b.top()]++;
			b.pop();
		}
		
	}
	for(int i=0;i<fl+1;i++)
	{
		if(ty[i])
			cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}
