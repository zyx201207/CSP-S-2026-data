#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+6;
int n,a[N];
unsigned long long m; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	
	
	int ans = 0 ;
	for(int i=1;i<=n;i++){
		unsigned long long lm = m;
		int j=i-1,ans1=1;
		while(1){
			if(a[j] == a[i]){
				ans1++;
				j--;
			}
			if(j<=0 || lm <= 0)break;
			a[j]++;
			lm--;
		}
		ans = max(ans,ans1);
	}	
	cout << ans;

	return 0;
} 
