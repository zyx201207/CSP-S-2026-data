#include<bits/stdc++.h>
using namespace std;
long long n,v;
long long a[200005] = {0};
long long dfs(int c,long long x,long long m,long long shu){
	if(c == v+1){
		return max(m,shu);
	}
	if(a[x] < m){
		return m;
	}
	for(int i = n;i > 0;i--){
		int l = a[x];
		a[x] = -1;
		shu = (c == 1 ? l : shu & l);
		if(shu < m){
			continue;
		}
		m = max(m , dfs(c+1,i,m,shu));
		a[x] = l;
	}
	return m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> v;
	for(int i =  1; i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long m = 0;
	for(int i = n;i > 0;i--){
		m = max(m,dfs(1,i,0,0));
	}
	cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
