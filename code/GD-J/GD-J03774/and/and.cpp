#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[200010] , x[200010] , mc[35];
bool b[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	mc[0] = 1;
	for(int i = 1; i <= 30; i++){
		mc[i] = mc[i-1]*2;
	}
	for(int r = 30; r >= 0; r--){
		int cnt = 0;
		//cout << mc[r] << "/";
		for(int i = 1; i <= n; i++){
			if(a[i] >= mc[r]){
				cnt++;
				//cout << a[i] << " ";
				x[cnt] = a[i]-mc[r];
				a[i] = a[i]-mc[r];
			}
		}//cout << endl;
		if(cnt >= m){
			b[r] = 1;
			for(int i = 1; i <= cnt; i++){
				a[i] = x[i];
			}n = cnt;
		}
	}
	int z = 0;
	for(int i = 0; i <= 30; i++){
		if(b[i]) z += mc[i];
	}
	printf("%d",z);
	return 0;
}
