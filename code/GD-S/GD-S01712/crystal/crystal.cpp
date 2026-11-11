#include<bits/stdc++.h>
using namespace std;
bool flag1 = true,flag2 = true;
long long n,m,ans,a[500005],b[500005];
void solve(){
	int ans = 0,d = a[2] - a[1];
	for(int i = 0;i <= n - 1;i++){
		int lst = i * d;
		if(lst * (i + 1) / 2 <= m) ans = i + 1;
		else break;
	}
	cout<<ans;
	return;
} 
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) flag1 = false;
		if((a[i] - a[i - 1] != a[i - 1] - a[i - 2]) && (i >= 3)) flag2 = false;
	}
	if(flag1 || flag2){
		solve();
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		long long res = 0,lst = 0;
		for(int j = i;j >= 1;j--){
			if(lst + (a[i] - a[j]) <= m){
				res++;
				lst += (a[i] - a[j]);
			}else break;
		}	
		ans = max(ans,res);
	}
	cout<<ans;
	return 0;
} 
