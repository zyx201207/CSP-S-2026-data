#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , f[500005] , v , ans = 1 , j = 1 , sum , pos;
bool flag = true , flag1 = false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a+1 , a+n+1);
	f[1] = 1;
	for(long long i = 2 ; i <= n ; i ++){
		f[i] = f[i - 1] + 1;
		sum += (i - j) * (a[i] - a[i - 1]);
		if(sum > m){
			flag1 = false;	
		}
		while(sum > m && f[i] > 1){
			flag = true;
			flag1 = true;
			if(sum > m && j == i - 1){
				sum -= (a[j + 1] - a[j]) * (j - pos - 1);
				f[i] ++;
				flag = false;
			}
			else{
				sum -= (a[j + 1] - a[j]) * (j - pos);
			}
			f[i] --;
			if(flag == true){
				j ++;
			}
		}
		if(flag1 == true){
			pos = j - 1;	
		}
		if(f[i] == 2){
			sum = a[i] - a[i - 1];
		}
		if(f[i] == 1){
			sum = 0;
		}
		ans = max(ans , f[i]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
