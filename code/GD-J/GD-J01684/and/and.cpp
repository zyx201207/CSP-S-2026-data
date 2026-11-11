#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],s[200001],maxn = -1,h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a+0,a+n+0);
	for(int i = 0; i < n; i++){
		long long maxk = -1,nub = a[i];
		s[i] = 1;
		for(int j = 0; j < m-1; j++){
			for(int k = 0; k < n; k++){
				if(s[k] != 1){
					long long num = nub&a[k];
					if(num > maxk){
						maxk = num;
						h = k;
					}
				}
			}
			s[h] = 1;
			nub = nub&a[h];
		}
		for(int j = 0; j < n; j++){
			s[j] = 0;
		}
		if(maxn < nub)maxn = nub;
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
