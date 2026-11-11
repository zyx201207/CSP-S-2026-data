#include <iostream> 
#include <algorithm>
using namespace std;
#define int long long
int n,l,r;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string sum='';
	while(n--)
	{
		int a;
		string b;
		cin>>a>>b;
		r+=a;
		for(int i=1;i<=a;i++)
		{
			sum+=b;
		}
	}
	l=0,r-=1;
	int ans=0;
	while(l<=r)
	{
		if(sum[l]!=sum[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin)
	fclose(stdout);
}
