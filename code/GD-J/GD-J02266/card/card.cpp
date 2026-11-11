#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[5000005],c[5000005];
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int id = 0;
	for(int p = 1; p <= n; p++){
		for(int i = 1; i <= n; i++){
			b[i] = 0;
		}
		for(int i = p; i <= n; i++){
			b[i] = a[i];
			for(int j = 1; j <= i ; j++){
				if(a[i] == b[j]){
					for(int k = j+1; k <= i; k++){
						b[k] = 0;
					}
				}
			}
		}
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				if(b[k] == j){
					c[j]++;
					break;
				}
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << c[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
