#include<bits/stdc++.h>
using namespace std;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char a;
		cin>>x>>a;
		for(int j=s;j<=s+x-1;j++)
		{
			c+=a;
		}
		s+=x;
	}
//	cin>>c;
//	s=c.size();
		for(int i=0;i<=s/2-1;i++)
		{
			if(c[i]!=c[s-i-1])
			{
				ans++;
			}
		}
		cout<<ans;

	return 0;
}

