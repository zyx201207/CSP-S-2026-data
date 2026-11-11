#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	cout << a[m-1];
//	int l=0,r=1;
//	int ans = a[0],maxans = -1e4;
//	for(int r=1;r<n*(n-1)/2/l;r++){			//遍历次数 
//		for(int l=0;l<n;l++){
//			for(int j=0;j<m;j++){
//				ans = ans & a[l+j];		//分别按位与 按位与的值： 
//				cout << ans << endl;
//			}
//			maxans = max(maxans,ans);		//求最大 
//		}
//	}
//	cout << maxans;
	return 0;
}
//遍历组合->分别按位与（&）->求最大
//**遍历组合：左指针每个值对应右指针的n和n+1……n依次递增 
//分别按位与：循环m次分别按位与组合中的数 
