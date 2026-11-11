//贵阳市第一中学  黄弈嘉  GZ-S00217
#include <bits/stdc++.h>
using namespace std;
/*
本题实际上所指的是存在最多的(a1+a2+a3+..an+m) >= n max(a1,a2,a3,a4,.....an)
那么我们考虑一下：先对A数组进行一个排列，排列后，我们对A做前缀和的操作，记数组为B。之后我们每一次的操作如下：
1、判断b[i] - b[i-k] + m >= k*a[i] , k为之前的最大长度，若可行：则：
2、for(int j = k+1;;j++){
		if(b[i] - b[i-j] + m < k*a[i]){
			k = j-1;
			break;
		}
		if(j == i){
			k = i;
			break;
		}
	}
这样我们就能找到最长的一根子串，使得它能够通过m次操作达到全部相同的效果。
*/
long long n,m;
const long long N = 5e5 + 5;
long long a[N],b[N],k;
 signed main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(long long i = 1;i <= n;i++) cin>>a[i];
 	sort(a+1,a+n+1); //初始化a数组
 	b[1] = a[1];
	for(long long i = 2;i <= n;i++){
		b[i] = b[i-1]+a[i];
	}
	k = 1;
	for(long long i = 2;i <= n;i++){
		if(b[i] - b[i-k] + m >= k*a[i]){
			for(long long j = k+1;;j++){
				if(b[i] - b[i-j] + m < j * a[i]){
					k = j-1;
					break;
				}
				if(j == i){
					k = i;
					break;
				}
			}
		}
	}
 	cout<<k;
 	return 0;
 }

