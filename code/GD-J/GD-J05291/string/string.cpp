#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0,cnt=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int a;
    	char c;
    	cin>>a>>c;
    	for(int i=0;i<a;i++)
    	{
    		s+=c;
		}
	}
	char t=s[0];
	long long f=s.size();
	for(int i=0;i<f;i++)
	{
		if(t==s[i])
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt==f)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<f/2;i++)
	{
		if(s[i]!=s[f-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
