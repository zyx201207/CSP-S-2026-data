#include<bits/stdc++.h>
using namespace std;
long long ansnum = -1,maxn = -1,n,m;
long long linshi[200005],ans[200005],er[200005][200005],a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long t = m;
	for(int i = 1;i <= n;i++){
		cin >> a;
		long long io = 1;
		while(a > 0){
			linshi[io] = a % 2;
			a /= 2;
			io++;
		}
		for(int j = 1;j <= io;j++){
			er[i][j] = linshi[io - j];
		}
		maxn = max(maxn,io);
	}
	for(long long i = maxn;i >= 1;i--){
		for(int j = 1;j <= n;j++){
			if(er[j][i] != 0 && t > 0){
				ansnum = max(ansnum,i);
				for(int k = i;k <= ansnum;k++){
					if(t == m) ans[k] = er[j][k];
					else{
						if(ans[k] == 1 && er[j][k] == 1) ans[k] = 1;
						else ans[k] = 0;
					}
				}
				t--;
			}
			if(t <= 0) break;
		}
	}
	long long ansr = 0,sum = 1;
	for(long long i = 1;i <= ansnum;i++){
		ansr += ans[i] * sum;
		sum *= 2;
	}
	cout << ansr;
	return 0;
} 
