#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
long long a[N];
char c[N];
int n;
long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	} 
	long long i = 1,j = n;
	while(i < j){
		if(c[i] == c[j]){
			if(a[i] == a[j]){
				i++;j--;
			}else if(a[i] < a[j]){
				a[j] = a[j] - a[i];
				i++;
			}else if(a[i] > a[j]){
				a[i] = a[i] - a[j];
				j--;
			}
		}else if(c[i] != c[j]){
			if(a[i] < a[j]){
				ans += a[i];
				a[j] -= a[i];
				i++;
			}else if(a[i] > a[j]){
				ans += a[j];
				a[i] -= a[j];
				j--;
			}else if(a[i] == a[j]){
				ans += a[i];
				i++;j--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
