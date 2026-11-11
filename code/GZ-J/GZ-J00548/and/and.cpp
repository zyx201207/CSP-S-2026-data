//GZ-J00548   遵义四中 王睿博 
#include <bits/stdc++.h>
using namespace std;

int n , m;
long long a[200005];
long long maxn = -1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n - 1 ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			if(a[i] & a[j] > maxn){
				maxn = a[i] & a[j];
			}
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
