#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,cnt=0,n,ans=-1;
	cin>>n;
	string S;
	char p;
	cin>>a;
	for (int i=0;i<n;i++)
	{
		for(int j=ans+1;j<=ans+a;j++)
		{
			cin>>p;
			if (int(p)>=97 && int(p)<=122)
			{
				for(int k=j;k<=ans+a;k++)
				{
					S[k]=p;
					cout<<S[k];
				}
			}
    	}
    	ans=a;
    	cin>>a;
	}
	sort(S.begin(),S.end());
	for (int i=1;i<=S.size();i++)
	{
		if (S[i-1]!=S[S.size()-i])
		{
			S[i-1]=S[S.size()-i];
		}
		else
		{
			cout<<S[i-1];
		}
	}
	return 0;
}
