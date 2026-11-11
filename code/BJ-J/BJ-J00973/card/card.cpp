#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],num = 1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int i = n,j = num;
	while(num<=n){
		i = n;
		j = num;
		while(i >= num){
			while(j <= i){
				while(a[i]==a[j]){
					ans[a[i]]++;
					i = j-1;
					j = num;
				}
				j++;
			}
			i--;
		}
		num++;
		

	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
