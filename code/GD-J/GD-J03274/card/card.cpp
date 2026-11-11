#include <bits/stdc++.h>
using namespace std;

int mjs[3005],mcs[200005],sf[200005]; 

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> mcs[i];
	}

	if (n <= 5000){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				sf[j] = true;
			}
			for (int j = i;j <= n;j++){
				for (int k = i;k < j;k++){
					if (mcs[j] == mcs[k]){
						for (int l = k;l < j;l++){
							sf[l] = false;
						}
					}
				}
			}
			for (int j = 1;j <= n;j++){
				if (sf[j]){
					mjs[mcs[j]]++;
				}
			}
		}
		for (int i = 1;i <= m;i++){
			cout << mjs[i] << " ";
		}
	}
	return 0; 
} 
