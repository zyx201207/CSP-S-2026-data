#include <bits/stdc++.h>
using namespace std;
long long n,m,two[35]= {},ans = 0,tmp,i;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	while(n--){
		cin >> tmp;
		i = 0;
		while(tmp){
			if(tmp % 2 == 1) two[i]++;
			tmp /= 2;
			i++;
		}
	}
	for(int j = 30;j >= 0;j--){
		if(two[j] >= m){
			long long sum = 1;
			for(int k = 1;k <= j;k++){
				sum *= 2;
			}
			ans += sum;
		}
	}
	cout << ans;
	return 0;
} 
