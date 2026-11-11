#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string num="";
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;char c;
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++)
		{
			num+=c;
		}
	}
	int l=0,r=len-1,cnt=0;
	while(l<r)
	{
		if(num[l]!=num[r]) cnt++;
		l++;r--;
	}
	cout<<cnt<<endl;
	return 0;
}
