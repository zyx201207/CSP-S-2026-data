#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000300],ans = -1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	for(long long i = 1;i <= n;i ++){
		cin>> a[i];
	}
	sort(a + 1, a + n + 1);
	for(long long mid = 2;mid <= n; mid++){    //遍历最终数
		if(a[mid] == a[mid+1])	continue;    //筛掉重复
		long long m2 = m,cnt = 0;	//重置
		for(long long i = mid;i >= 1;i --){
			if(a[mid] - a[i] <= m2){
				m2 -= (a[mid] - a[i]);	//消耗操作次数
				cnt ++;
			}
		}
		ans = max(ans,cnt);	
	}
	cout<< ans << endl;
	return 0;
}
