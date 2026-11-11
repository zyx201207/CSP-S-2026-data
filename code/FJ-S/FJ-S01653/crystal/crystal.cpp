#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 5e5 + 5;
int n;
long long m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	int tail = 1,ans = 1,head = 1;
	int sum = 0;
	while(head < n){
		while(head < n && (sum + (a[head + 1] - a[head]) * (head - tail + 1)) <= m){
			sum = sum + (a[head + 1] - a[head]) * (head - tail + 1);
			head++;
			ans = max(ans,head - tail + 1);
			//cout << head <<" "<< sum <<" " << m << endl;
		} 
		tail++;
		sum = sum - (a[head] - a[tail]);
	}
	printf("%lld",ans);
	return 0;
}

