#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool c[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans = 0;
	scanf("%d%d" ,&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&a[i]);
	}
	for(int i = 29;i >= 0;i--){
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			if(!c[j]){
				cnt += (a[j] & (1 << i)) >> i;
			}
		}
		if(cnt >= m){
			ans += 1 << i;
			for(int j = 1;j <= n;j++){
				if(!(a[j] & (1 << i))){
					c[j] = 1;
				}
			}
		}
	}
	printf("%d" ,ans);
	return 0;
} 
