#include <iostream>
using namespace std;
long long a[200003],sum,ans;
char c[100000003],bbv;
int n,poi;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	poi = 1;
	for (int i = 1;i<=n;i++){
		cin >> a[i] >> bbv;
		sum+=a[i];
		for (int j = poi;j<=a[i]+poi-1;j++){
			c[j] = bbv;
		}
		poi+=a[i];
	}
	if(sum%2==0){
		poi = sum / 2;
		for(int i = 1;i<=poi;i++){
			for(int j = sum+1-i;j>poi;j--){
				if(c[i] != c[j]){
					ans++;
				}
				break;
			}
		}
	}
	else{
		poi = sum / 2 + 1;
		for(int i = 1;i<poi;i++){
			for(int j = sum+1-i;j>poi;j--){
				if(c[i] != c[j]){
					ans++;
				}
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
