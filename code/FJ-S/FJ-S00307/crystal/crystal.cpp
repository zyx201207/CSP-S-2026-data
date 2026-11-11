#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5e5 + 15;
long long n,m,x,y,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	for (int i = 0;i < n;i++){
		x = 1;
		y = m;
		for (int j = i - 1;j >= 0;j--){
			if (y >= a[i] - a[j]){
				y -= a[i] - a[j];
				x++;
			}else{
				break;
			}
		}
		ans = max(ans,x);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
