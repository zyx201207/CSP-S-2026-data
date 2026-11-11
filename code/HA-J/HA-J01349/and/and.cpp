#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[32][200005];
int now[200005];
int m,n,ans;
void dp(int k,int ll){
	for (int i = ll; i >= 1; i--){
		int num = 0;
		for (int j = 1; j <= k; j++){
			if(b[i][now[j]] == '1'){
				num++;
				//now[num] = j;
			}
		}
		if(num >= m){
			num = 0;
			for (int j = 1; j <= k; j++){
				if(b[i][now[j]] == '1'){
					num++;
					now[num] = now[j];
			}
		}
		ans += pow(2,i-1);
			dp(num,i-1);
			break;
	}
}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	int maxl = 0,l;
	for (int i = 1; i <= n; i++){
		cin >> a[i] ;
		l = 0;
		while(a[i] > 0){
			l++;
			int p = a[i] % 2;
			if(p == 1) b[l][i] = '1';
			else b[l][i] = '0';
			a[i] /= 2;
		}
		maxl = max(maxl,l);
		now[i] = i;
	}
	dp(n,maxl);
	cout << ans ;
	return 0;
}
