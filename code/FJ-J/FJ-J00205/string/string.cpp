#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,ans,now;
struct node{
	int num;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].num>a[r].num) 
			{
				a[l].num-=a[r--].num;
//				now+=a[r++].num;
			}
			else if(a[r].num>a[l].num) 
			{
				a[r].num-=a[l++].num;
//				now+=a[l++].num;
			}
			else 
			{
//				now+=a[l].num;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].num>a[r].num)
			{
				a[l].num-=a[r].num;
//				now+=a[r++].num;
				ans+=a[r--].num;
			}
			else if(a[r].num>a[l].num)
			{
				a[r].num-=a[l].num;
				ans+=a[l++].num;
//				now+=a[l++].num;
			}
			else
			{
//				now+=a[l].num;
				ans+=a[l].num;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
