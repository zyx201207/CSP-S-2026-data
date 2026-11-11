#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , c[N] , lst[N] , tg[N];
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	bool flag = true;
	for(int i = 1;i < n;i++){
		if(a[i] > a[i + 1])flag = false;
	}
	if(flag){
		for(int i = 2;i <= n;i++){
			if(a[i] != a[i - 1])c[a[i - 1]] = i - 1;
		}
		c[a[n]] = n;
		for(int i = 1;i <= m;i++)cout << c[i] << ' ';
		return 0;
	}
	if(n <= 500){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++)lst[j] = f[j] = 0;
			for(int j = i;j <= n;j++){
				if(f[a[j]]){
					for(int k = lst[a[j]];k < j;k++)f[a[k]] = false;
				}
				f[a[j]] = true;
				lst[a[j]] = j;
			}
			for(int j = 1;j <= m;j++)c[j] += f[j];
		}
		for(int i = 1;i <= m;i++)cout << c[i] << ' ';
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)lst[j] = f[j] = 0;
		for(int j = 1;j <= n;j++)tg[j] = 0;
		for(int j = i;j <= n;j++){
			if(f[a[j]])tg[lst[a[j]]]++ , tg[j]--;
			f[a[j]] = true;
			lst[a[j]] = j;
		}
		for(int j = i;j <= n;j++)tg[j] += tg[j - 1];
		for(int j = 1;j <= m;j++){
			if(f[j] && tg[lst[j]] == 0)c[j]++;
		}
	}
	for(int i = 1;i <= m;i++)cout << c[i] << ' ';
	return 0;
}
