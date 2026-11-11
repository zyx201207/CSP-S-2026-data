#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010],s[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
	int ans = 0;
	int l = 1,r = n,best;
	while(l <= r){
		int flag = 0;
		int i = (l + r) / 2;
		for (int j = 1;j + i - 1 <= n;j++){
			if (a[i+j-1] * i - (s[j+i-1]-s[j-1]) <= m){
				ans = max(ans,i);
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			r = i - 1;
		}
		else{
			best = i;
			l = i + 1;
		}
	}
	printf("%d",ans);
	return 0;
}
