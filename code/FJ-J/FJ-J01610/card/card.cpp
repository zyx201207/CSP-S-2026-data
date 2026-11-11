#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[300005];//数，值 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if(n == 1 && m == 1){
		cout << 1;
	}
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){//局数 
		int b[300005],r[300005],rmax = i;//数出现的次数，最右边的点 
		for(int j = i;j <= n;j++) b[a[j]]++,r[a[j]] = j;//统计数出现次数和最右边的点的下标  
		for(int k = 1;k <= m;k++){//查找最右边的点并且要为偶数 
			if(b[k] % 2 == 0){
				if(rmax < r[k]) rmax = r[k]; 
			} 
		} 
		for(int l = rmax;l <= n;l++){//相加 
			s[a[l]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << s[i] << " ";
	}
	return 0;
}

