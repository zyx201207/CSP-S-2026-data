#include <bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[500001];
long long diff;//代价 
long long ans;//当前时刻，可以合成大水晶的能量水晶数量 
long long ans2;//最终答案 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);//从小到大排序
	for(int i=1;i<=n;i++)
	{
		//1.添加代价diff（如果i=1则不需要） 
		if(i>1)diff+=ans*(a[i]-a[i-1]);
		
		ans++;//2.包含位置i作为能量水晶
		
		//3.排掉不符合条件的能量水晶
		while(diff>m)
		{
			//删除位置为i-ans+1的能量水晶
			int v=i-ans+1;
			ans--;
			diff-=a[i]-a[v];//释放代价 
		}
		
		//cout << i << " " << ans << " " << diff << '\n'; 
		
		ans2=max(ans2,ans); 
	} 
	cout << ans2;
}
