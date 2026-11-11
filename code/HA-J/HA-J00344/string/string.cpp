#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll N=1000000+7;
ll n,cnt=0,nt;
string s;
int check()
{
	ll l=0,r=n;
	while(l+1<r)
	{
		if(s[l]!=s[r])
		{
			nt++;
		}
		l++;
		r--;
	}
	return nt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ll ls;
	char air;
	for(int i=1;i<=n;i++)
	{
		cin>>ls;
		cin>>air;
		//cout<<air<<endl;
		for(int j=cnt;j<ls;j++)
		{
			//cout<<"///";
			s[j]='air';
		}
		cnt+=ls;
	}
	cout<<check();
	return 0;
}
