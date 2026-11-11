#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m;
int arr[N];
int qzh[N];
int sum,ans=0;
bool check(int x,int pos)
{
	if((arr[pos]*(pos-x+1)-(qzh[pos]-qzh[x-1]))<=m) return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	//cout<<1;
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+arr[i];
		int l=1,r=i,res=0;
		//cout<<1;
		while(l<=r)
		{
			int mid=l+r>>1;
			//cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid,i)<<endl;
			if(check(mid,i))
			{
				res=mid;
				r=mid-1;
			} 
			else 
			{
				l=mid+1;
			}
		}
		//cout<<1<<endl;
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
