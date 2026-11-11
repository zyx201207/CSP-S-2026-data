#include<bits/stdc++.h>
using namespace std;
long long n,i,c[32],ans,j,x,w,b[200005];
long long a[200005][32],s,cnt,k,maxn;
bool flag,f[200005];
void to0b(long long x){
	long long t = s;
	while(x){
		a[i][t] = x%2;
		x /= 2;
		t--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(i=1;i<=n;i++){
		cin >> b[i];
		maxn = max(maxn,b[i]);
	}
	s = floor(log2(maxn))+1;
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)to0b(b[i]);
	for(i=1;i<=s;i++){
		cnt = 0;
		for(j=1;j<=n;j++){	
			if(flag && !a[j][i-1])f[j] = 1;
			if(f[j])continue;
			if(a[j][i])cnt++;
		}
		if(cnt < k)flag = 0;
		else{
			c[i] = 1;
			flag = 1;
		}
	}
	for(i=1;i<=s;i++)
		if(c[i])ans += pow(2,s-i);
	cout << ans;
	return 0;
}
