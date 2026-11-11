#include<bits/stdc++.h>
using namespace std;
unsigned long long sum;
long long c, n, m, d, q,k,jd,jdt;
long long w[100000007],a[100000007],t[100000007],xr[100000007],yr[100000007],dk[100000007][100000007],dk1[100000007][100000007];
long long ton[100000007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i]; 
	} 
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j]>>t[j];
			dk[i][j] = a[j];
			dk1[i][j] = t[j];
			ton[dk[i][j]]++;
			if(ton[i]!=1){
				jd = i;
			}if(dk[i][j]==jd){
				jdt+=dk1[i][j];
			}
		}
		
	}
	

	for(int i = 1;i <= q;i++){
		cin >> xr[i] >> yr[i];
	}
	for(int i = 1;i <= q;i++){
		sum = w[xr[i]]+w[yr[i]]+jdt+dk1[1][xr[i]]+dk1[2][yr[i]];
		cout << sum << "\n";
	} 
	
	return 0;
} 

