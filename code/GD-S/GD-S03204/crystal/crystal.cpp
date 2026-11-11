#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
const int C=1e12;
int n,m;
int sum[N];
int arr[N];
int l,r,mid;
void find(int x)//向前面找到最长的 
{
	l=1,r=x,mid;
	while(l<=r)
	{
//		cout<<mid<<" ";
		mid=(l+r)>>1;
		if((x-mid+1)*arr[x]-sum[x]+sum[mid-1]>m)
		{
			l=mid+1;
		}
		else r=mid-1;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i]+=C+1;
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+arr[i];
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<mid<<" "<<(i-mid+1)*arr[i]-sum[i]+sum[mid-1]<<endl;
		
		while(((i-mid+1)*arr[i]-sum[i]+sum[mid-1])>m)
			mid++;
//		if(res<(i-mid+1))cout<<"FIND THE ANS!!!\n";
		res=max(res,(i-mid+1));
		
	}
	cout<<res<<endl;
 } 
 /*
 5  5 1 2 4 8 9
 */
