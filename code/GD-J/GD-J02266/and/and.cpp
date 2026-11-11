#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
int main(){
	cin >> n >> m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxx = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if(m == 1){
			cout << maxx;
		}else if(m == 2){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i != j){
						maxx = max(maxx,a[i]&a[j]);
					}
				}
			}
		}
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
