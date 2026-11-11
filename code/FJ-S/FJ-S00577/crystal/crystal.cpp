#include <bits/stdc++.h>
using namespace std;

int n,ans,st,ed;
long long m,a[500005],esum;

int read(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar())
		if(c == '-')
			f = -1;
	for(;isdigit(c);c = getchar())
		k = k*10 + (c^48);
	return k*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	n = read(),m = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	sort(a+1,a+n+1); 
	ans = 1;
	esum = 0,st = 1,ed = 1;
	for(int i = 2;i <= n;i++){
		esum += (a[i]-a[i-1])*(ed-st+1);
		while(!(a[st]+m >= a[i] && esum <= m)){
			esum = esum - (a[i] - a[st]);
			st++;
		}
		ed++;
		ans = max(ans,ed-st+1);
	}
	cout << ans;
	
	return 0;
}
