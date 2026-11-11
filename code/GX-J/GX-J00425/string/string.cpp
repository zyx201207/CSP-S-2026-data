#include <bits/stdc++.h>
#define LL long long
#define AC return 0
using namespace std;
const int N=2e5+10;
int n,ans;
string s="";
inline void LI()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
			s=s+c;
	}
	int len=s.size();
	for(int i=0,j=len-1;i<=j;i++,j--)
		if(s[i]!=s[j])
			ans++;
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
//  cin>>t;
	while(t--)
		LI();
	AC;//rp+=INF
}
