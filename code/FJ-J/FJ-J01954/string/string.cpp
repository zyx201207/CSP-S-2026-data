#include<bits/stdc++.h>
#define int long long
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n' 
using namespace std;
using pii=pair<int,int>;
int n,cnt;
int a[200010];
char c[200010];
void d()
{
	cin>>n;
	int y=0;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}	
	int cnt=0;
	int r=s.size()-1;
	for(int i=0;i<=(s.size()-1)/2;i++)
	{
		if(s[i]!=s[r])	cnt++;
		r--;
	}
	cout<<cnt<<endl;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t; 
	while(t--)d();
}
