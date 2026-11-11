#include<bits/stdc++.h>
using namespace std;
int compbin(long long a,long long b){
	int nua[64] = {},nub[64] = {};
	memset(nua,0,sizeof nua);
	memset(nub,0,sizeof nub);
	int na = 0;
	while(a > 0){
		nua[na] = a % 2;
		na++;
		a /= 2;
	}
	int nb = 0;
	while(b > 0){
		nub[nb] = b % 2;
		nb++;
		b /= 2;
	}
	int ans = 0;
	for(int i = 0;i < min(na,nb);i++){
		if(nua[i] == nub[i]) ans ++;
	}
	return ans;
}
int a[200005] = {};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		cout << a[1];
	}
	else{
		int maxn = INT_MIN,pos1 = -1,pos2 = -1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(compbin(a[i],a[j]) > maxn){
					pos1 = i,pos2 = j;
					maxn = compbin(a[i],a[j]);
			}
		}
	}
		if(m == 2) cout << (a[pos1] & a[pos2]);
		else{
			int now = (a[pos1] & a[pos2]);
			a[pos1] = -1,a[pos2] = -1;
			for(int i = 1;i <= m - 2;i++){
				int maxn = INT_MIN,pos = -1;
				for(int j = 1;j <= n;j++){
					if(compbin(now,a[j]) > maxn){
						pos = j;
						maxn = compbin(a[i],a[j]);
					}
					if(a[j] == -1){
						continue;
					}
				}
				now = (now & a[pos]);
				a[pos] = -1;
			}
			cout << now;
	}
}
}
