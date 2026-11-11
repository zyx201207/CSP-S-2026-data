#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans = 0;
	int i = 1,j = a[i],k = n,l = a[k];
	while(i < k){
		if (c[i] != c[k]){
			ans += min(j,l);
		}
		int m = min(j,l);
		j -= m;
		l -= m;
		if (j == 0){
			i++;
			j = a[i];
		}
		if (l == 0){
			k--;
			l = a[k];
		}
	}
	printf("%lld",ans);
	return 0;
}
