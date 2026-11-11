#include <iostream>
using namespace std;
long long n,m,arr[500010],crr[215000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> arr[i];
	for(long long i = 1;i <= n;i++){
		long long trr[500010] = {0},k = 0;
		bool flag[215000];
		for(long long j = i;j <= n;j++){
			if(!flag[arr[j]]){
				flag[arr[j]] = true;
				trr[++k] = arr[j];
			}
			else{
				for(long long o = 1;o <= k;o++){
					flag[trr[o]] = false;
					trr[o] = 0;
				}
				k = 0;
				trr[++k] = arr[j];
			}
		}
		for(long long j = 1;j <= k;j++) crr[trr[j]]++;
	}
	for(long long i = 1;i <= m;i++) cout << crr[i] << " ";
	return 0;
}
