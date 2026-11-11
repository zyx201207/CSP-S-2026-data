#include<bits/stdc++.h>
using namespace std;
int a[200005],Ans;
char c[200005];
int head,ans;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		{		
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			head++;
			s[head]=c[i];
		}
		}
	for(int i=1;i<=(head+1)/2;i++)
	{
		if(s[head+1-i]!=s[i])
			Ans++;
	}
	cout<<Ans;
	return 0;
	
}
