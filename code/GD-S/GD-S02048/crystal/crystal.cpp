#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;
int a[500005];
int c = 1;
int main(){
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) c = 0;
	}
	if(c == 1){
		cout << int(sqrt(m*2));
		return 0;
	}
	sort(a+1,a+n+1);
	
	int w=1,e=a[2]-a[1];
	for(int i = 3;i <= n;i++){
		if(e != a[i]-a[i-1]) w=0;
	}
	
	if(w == 1){
		cout << int(sqrt(m*2/sqrt(e)));
		return 0;
	}
	
	int ans = 1;
	for(int i = 1;i <= n;i++){
		long long sum = 0;
		int as = 1;
		for(int j = i-1;j >= 1;j--){
			sum += a[i]-a[j];
			if(sum > m) break;
			as++;
		}
		ans = max(ans,as);
	}
	cout << ans;
	
	return 0;
}