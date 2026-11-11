#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=5e5+10;
int a[N],qsum[N],ans=1,n,m;
signed main  ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	// 从小到大排序  
	for (int i=1;i<=n;i++) qsum[i]=qsum[i-1]+a[i];
	for (int i=1;i<=n;i++)// 外层循环枚举n  基准数字   能不能完整合并评判标准 （i*m-qsum[i-1]）<= m     
	{
		if ((i-1)*a[i]-qsum[i-1]<=m) 
		{
			ans=max(ans,i); //前i个可以合并 
//			cout<<i<<"可以合并"<<endl; 
		}
		else // 如果是无法完全合并的  二分尽量合并多一点    
		{
			int l=1,r=i-1;
			while (l<r)  //左边的最大  可以合并时l最小值 
			{
				int mid=(l+r)/2;
				int t=a[i]*(i-mid)-(qsum[i-1]-qsum[mid-1]);
				if (t<=m)
				{
					r=mid; 
				}
				else 
				{
					l=mid+1;
				} 
			}
			int t=a[i]*(i-l)-(qsum[i-1]-qsum[l-1]) ;
			if (t<=m)ans=max(ans,i-l+1);
//			cout<<l<<"部分合并"<<endl; 
		}
	}
	cout<<ans;
	return 0; 
} 
