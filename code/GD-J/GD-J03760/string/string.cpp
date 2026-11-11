#include<iostream>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
int n,ans;
struct node{
	int num;
	char a;
}s[300000];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].num>>s[i].a;
	int i=1,j=n;
	while(i<j)
	{
		int t=min(s[i].num,s[j].num);
		if(s[i].a!=s[j].a) ans+=t;
		s[i].num-=t;
		s[j].num-=t;
		if(s[i].num==0) i++;
		if(s[j].num==0) j--;
	}
	cout<<ans;
	return 0;
} 
