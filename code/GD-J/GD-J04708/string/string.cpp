#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct node{
	int l,r;
	char c;
};
const int N=2e5+10;
int n,len,mid,ans;
node a[N];
string str;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		char c;
		cin>>t>>c;
		for(int j=1;j<=t;j++)
			str+=c;
		len+=t;
	}
	mid=len>>1;
	for(int i=0;i<mid;i++)
	{
		if(str[i]!=str[len-i-1])
			ans++;
	}
	cout<<ans;
}
