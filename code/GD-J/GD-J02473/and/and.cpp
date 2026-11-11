#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int num[200010];
int sf4[4];
int ans=0;
int n,m;
inline int max(int a, int b) {return a>b?a:b;}
void dfs(int depth, int place, int number) {
	if(depth == m) {
		ans = max(ans,number);
		return;
	}
	for(int i=place+1; i<=n ;i++) {
		if(depth == 0) dfs(depth+1,i,num[i]);
		else dfs(depth+1,i,number&num[i]);
		
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool s4=true;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> num[i];
		if(num[i] >= 4) s4=false;
		else sf4[num[i]]++;
	}
	if(s4) {
		if(sf4[3]>=m) ans=3;
		else if(sf4[3] + sf4[2] >= m) ans=2;
		else if(sf4[3] + sf4[1] >= m) ans=1;
		else ans=0;
	} else {
		dfs(0,0,0);
	}
	cout << ans;
	return 0;
}

