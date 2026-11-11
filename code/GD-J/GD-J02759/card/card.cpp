#include <bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[500005],b[500005],c[500005];
int main() {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int k = 1;k <= n;k++){
		for(int i = k;i <= n;i++) c[i] = a[i];
		for(int i = k;i <= n;i++){
			for(int j = k;j < i;j++){
				if(c[j] == c[i]){
					for(int x = j;x < i;x++) c[x] = 0;
				}
			}
			
		}
		for(int j = 1;j <= m;j ++){
					if(c[j] > 0) b[c[j]]++;	
				}
				for(int j = 1;j <= m;j++) cout << b[j] << " ";
				cout << endl;
	}
	for(int i = 1;i <= m;i++) cout << b[i] << " ";
	return 0;
}
