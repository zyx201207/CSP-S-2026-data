#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	bool flag=1;
	int d=0; 
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i == 1) continue;
		if(i == 2) d = a[i] - a[i-1];
		if(a[i] - a[i-1] != d) flag = 0;
	} 
	if(flag){
		int k=0;
		for(int i = 1;i<=n;i++){
			if(k == m){
				cout << i;
				break;
			}
			if(k > m){
				cout << i - 1;
				break; 
			}
			k += i * d;
			
		}
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=0,k=0;
	flag=0;
	for(int i = 1;i<=n;i++){
		int m1 = m,b=0,cnt=0;
		for(int j = i;j<=n;j++){
			k++;
			if(m1 >= b * (a[j] - a[j-1])){
				cnt++;
				m1 -= b * (a[j] - a[j-1]);
				b++;
			}else break;
			if(k > 100000000){
				flag = 1;
				break;
			}
		} 
		ans = max(cnt,ans);
		if(flag) break;
	}
	printf("%lld",ans);
	return 0;
} 
