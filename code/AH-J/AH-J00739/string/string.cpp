#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string a;
	string s="";
	long long m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>a[i];
		for(int j=1;j<=m;j++)
		s+=a[i];
    }
    long long ans=0;
    int num=s.length();
    for(int i=0;i<num/2;i++)
    {
		if(s[i]!=s[num-1-i])
		ans++;
	}
	cout<<ans;
	return 0;
}
