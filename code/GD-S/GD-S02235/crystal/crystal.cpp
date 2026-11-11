#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long cha = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	bool kl = 1;
	cha = a[2]-a[1];
	for(int i = 2; i <= n; i++){
		if(a[i]-a[i-1] != cha){
			kl = 0;
		}
	}
	sort(a+1,a+n+1);
	long long ans = 0;
	long long p = m;
	long long maxx = -1;
	if(kl == 0){
		for(int i = 1; i <= n; i++){
			ans = 0;
			p = m;
			for(int j = i; j >= 1; j--){
				//cout << a[i] << ' ' << a[j]  << ' ' << p <<' ' << ans << endl;
				if(p >= (a[i]-a[j])){
					p -= (a[i]-a[j]);
					ans++;
				}
			}
			maxx = max(maxx,ans);
		}
		cout << maxx;
	}else{
		long long cha = a[2]-a[1];
		for(int i = 1; i <= n; i++){
			if(p >= (a[1]+(i-1)*cha)){
				p -= (a[1]+(i-1)*cha);
				ans++;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
