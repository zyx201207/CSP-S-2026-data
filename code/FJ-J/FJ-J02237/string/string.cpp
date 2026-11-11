#include<bits/stdc++.h>
using namespace std;
long long duan,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>duan;
	for(int i=1;i<=duan;i++)
	{
		int ge;
		char zm;
		cin>>ge>>zm;
		for(int j=1;j<=ge;j++)
			s+=zm;
	}
	long long l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
			ans++;
		l++;
		r--;	
	}
	cout<<ans;
}
