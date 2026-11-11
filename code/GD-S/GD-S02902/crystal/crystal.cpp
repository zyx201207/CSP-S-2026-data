#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<long long> a(n+1,0);
	for(long long i = 1;i <= n;i++){
		cin >>a[i];
	}
	sort(a.begin(),a.end());
	
	vector<long long> jishu(n+1,0);
	vector<long long> chazi(n+1,0);
	vector<long long> pre(n+1,0);
	
	int sfczzs = 0;
	int dengcha = 0;
	long long cha = a[2] - a[1];
	for(long long i = 1;i <= n;i++){
		 
		long long cnt = 1;
		if(i != n){
			chazi[i] = a[i+1] - a[i];
			if(chazi[i] != cha && i != n) dengcha = 1;//不是等差是1
		}
		for(long long j = 1;j <= n;j++){
			if(a[i] == a[j] && i != j) cnt += 1;
		}
		if(cnt != 1) sfczzs = 1;
		jishu[i] = cnt;
	}
	//记录zong数
	
	
	long long zst,zsf;
	//没有zong数,maybe只能求等差，等差就25（
//	if(sfczzs == 0){
//		for(long long i = 1;i <= n;i++){
//			if(i == 1) pre[1] = 1;
//			if(i > 1){
//				pre[i] = pre[i-1] + chazi[i]*(i - 1);
//			}
//		}
//		
//		
//		//双指针找最大区间
//		long long daan = 1;
//		for(int i = 1;i<=n;i++){
//			for(int j = i;j <= n;j++){
//				if(pre[j] - pre[i] - chazi[i]*i <= m){
//					if(daan < j - i){
//						daan = j - i + 1;
//					}
//				}
//			}
//		}
//		
//		
//		
//		zsf = daan;
//		cout << daan;
//	}
//	
//	//存在zong数,找最大zong数 
//	else{
//		int cfzs = 0;
//		long long zsnum = 1;
//		long long zs = a[1];
//		long long zsx = 1;
//		for(int i = 1;i <= n;i++){
//			if(zsnum < jishu[i] && zs != a[i]){
//				zsnum = jishu[i];
//				zs = a[i];
//				zsx = i;
//			}
//		}
//		
//		for(long long i = 1;i <= n;i++){
//			if(i > 1){
//				pre[i] += pre[i-1] + chazi[i]*(i - 1);
//			}
//		}
//		
//		long long daan = 1;
//		for(int i = zsx; i >= 1;i--){
//			if(pre[zsx] - pre[i] <= m && i != zsx){
//				daan += 1;
//			}
//		}
//		zst = daan+1;
//		cout << daan + 1;//你也要加1吗 
//	} 
	//cout << endl << "是否等差" << dengcha;
	if(dengcha == 0){
		for(long long i = 1;i <= n;i++){
			if(i == 1) pre[1] = 1;
			if(i > 1){
				pre[i] = pre[i-1] + chazi[i]*(i - 1);
			}
		}
		
		
		//双指针找最大区间
		long long daan = 1;
		for(int i = 1;i<=n;i++){
			for(int j = i;j <= n;j++){
				if(pre[j] - pre[i] - chazi[i]*(i - 1) <= m){
					if(daan < j - i + 1){
						daan = j - i + 1;
					}
				}
			}
		}
		
		
		
		zsf = daan;
		cout << daan - 1;
	}
	else{
		for(long long i = 1;i <= n;i++){
			if(i == 1) pre[1] = 1;
			if(i > 1){
				pre[i] = pre[i-1] + chazi[i]*(i - 1);
			}
		}
  		int cfzs = 0;
 		long long zsnum = 1;
 		long long zs = a[1];
 		long long zsx = 0;
 		for(int i = 1;i <= n;i++){
 			if(zsnum < jishu[i] && zs != a[i]){
 				zsnum = jishu[i];
 				zs = a[i];
 				zsx = i;
 			}
 		}
 		
		//双指针找最大区间
		long long daan = 1;
		long long jdzsx = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i;j <= n;j++){
				if(pre[j] - pre[i] - chazi[i]*i <= m){
					if(daan < j - i + 1){
						daan = j - i + 1;
					}
					if(j < zsx + zsnum - 1 && zsnum != 1){
						jdzsx = zsx + zsnum - 1 - j;
					}
				}
			}
		}
		
		
		
		zsf = daan;
		//cout << daan << endl;
		
		cout << daan + jdzsx;
	}
//	for(long long i = 1;i <= n;i++){
//			if(i == 1) pre[1] = 1;
//			if(i > 1){
//				pre[i] = pre[i-1] + chazi[i]*(i - 1);
//			}
//		}
//  		int cfzs = 0;
// 		long long zsnum = 1;
// 		long long zs = a[1];
// 		long long zsx = 1;
// 		for(int i = 1;i <= n;i++){
// 			if(zsnum < jishu[i] && zs != a[i]){
// 				zsnum = jishu[i];
// 				zs = a[i];
// 				zsx = i;
// 			}
// 		}
// 		
//		//双指针找最大区间
//		long long daan = 1;
//		for(int i = 1;i<=n;i++){
//			for(int j = i;j <= n;j++){
//				if(pre[j] - pre[i] - chazi[i]*i <= m){
//					if(daan < j - i + 1){
//						daan = j - i + 1;
//					}
//				}
//			}
//		}
//		
//		
//		
//		zsf = daan;
//		//cout << daan << endl;
//		cout << daan + zsnum - 1;
	//cout << endl << "是否等差" << dengcha;
	return 0;
}
