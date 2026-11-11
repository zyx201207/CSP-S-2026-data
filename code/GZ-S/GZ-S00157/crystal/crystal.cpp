//GZ-S00157 观山湖中学 王茗皓
#include<bits/stdc++.h>

using namespace std;

long long n,m,maa;
long long a[500001],l = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
	
		scanf("%lld",&a[i]);
	
		if(a[i] > 0)
			l+=a[i];
	}
	l /= n;
	
	sort(a + 1,a + n + 1);
	for(;m;){
		int s = 0;
		for(int i = 1;i <= n;i++){
			
			if(a[i] >= l){
				s++;
				continue;
			}
				
			a[i]++;
			m--;
		}
		if(s == n)
			break;
	}
	int ans = 0;
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i+1]){
			ans++;
		}
	}
	printf("%lld",ans + 1);
	return 0;
}