#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

typedef pair<int,int> PII; 
typedef long long LL;

LL a[N]; 
LL sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	LL m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		//a[i] += 1e12;
	}
		
	sort(a + 1,a + 1 + n);
	int ans = 0;
	LL sum1 = 0;
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
		int l = 1,r = i;
		while(l < r){
			int mid = l + r >> 1;
			if((LL)(i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		//cout<<(LL)(i) * a[i] - (sum[i])<<' '<<m<<'\n';
		ans = max(ans,i - l + 1);
		sum1 += a[n] - a[i];
	}
	cout<<ans<<'\n';
	
	return 0;
} 
