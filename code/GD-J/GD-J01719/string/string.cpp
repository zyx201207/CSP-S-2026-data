#include<bits/stdc++.h>
using namespace std;
int n;
long long mp[200005][3],len=1,l=1,r,ans;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s;
		char x;
		cin>>s>>x;
		mp[len][1]=s;mp[len][2]=x;
		++len;
	}
	r=n;
	while(l<=r)
	{
		if(l==r)
		{
			//ans+=mp[l][1];
			break;
		}
		if(mp[l][2]!=mp[r][2])
		{
			if(mp[l][1]>mp[r][1])
			{
				ans+=mp[r][1];mp[l][1]-=mp[r][1];--r;
			}else if(mp[l][1]<mp[r][1]){
				ans+=mp[l][1];mp[r][1]-=mp[l][1];++l;
			}else{
				ans+=mp[l][1];++l;--r;
			}
		}else{
			if(mp[l][1]>mp[r][1]){
				mp[l][1]-=mp[r][1];--r;
			}else if(mp[l][1]<mp[r][1]){
				mp[r][1]-=mp[l][1];++l;
			}else ++l,--r;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
