//六盘水市第二十四中学 廖奕然 GZ-J00598 
#include <bits/stdc++.h>
using namespace std;
int a[500100],b[500100],result[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[j] = a[j];
		}
		for(int j = i;j <= n;j++){
			for(int k = i;k <= j;k++){
				if(b[k] == b[j]){
					for(int l = k;l < j;l++){
						b[l] = 0;
					}
				}
			}
		}
		sort(b+i,b+1+n,greater<int>());
		for(int j = i;j <= n;j++){
			if(b[j] == 0){
				break;
			}
			for(int k = 1;k <= n;k++){
				if(b[j] == k){
					result[k]++;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(!result[i]){
			continue;
		}
		cout << result[i] << " ";
	}
	return 0;
}
