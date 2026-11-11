#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
struct node{
	int num;
	char c;
};
node arr[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].num>>arr[i].c;
	}
	int l=1,r=n;
	int res=0;
	while(l<r)
	{
//		cout<<"YES";
		if(arr[l].num==0)l++;
		if(arr[r].num==0)r--;
		if(arr[l].c!=arr[r].c)
		{
			int minn=min(arr[l].num,arr[r].num);
			arr[l].num-=minn;
			arr[r].num-=minn;
			res+=minn;
		}
		if(arr[l].c==arr[r].c)
		{
			int minn=min(arr[l].num,arr[r].num);
			arr[l].num-=minn;
			arr[r].num-=minn;
		}
		if(r-1==l&&arr[l].c==arr[r].c)break;
	}
	cout<<res;
}
