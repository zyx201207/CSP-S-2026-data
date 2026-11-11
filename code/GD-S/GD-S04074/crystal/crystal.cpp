#include<bits/stdc++.h>
using namespace std;
long long n,s=1,flag,ans;
long long m,a[500005],sum;
long long b[500005],maxx;
bool cmp(long long x,long long y){
	return x >= y;
}
void dfs(long long num,int x,long long cnt){
	if(cnt == 1) maxx = a[x];
	num += maxx - a[x];
	if(num > m){
		ans = max(ans,cnt-1);
		return;
	}else if(num == m){
		ans = max(ans,cnt);
		return;
	}for(int i = x+1;i <= n;i++)
		dfs(num,i,cnt+1);
		
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i >= 2)
			b[i] = a[i] - a[i-1];
		if(b[i] == b[i-1]) flag++;
	}if(flag == n-1){
		int i = 0;
		while(sum <= m){
			i++;
			sum += b[1]*i;
		}if(sum > m) i--;
		cout << i;
		return 0;
	}sort(a+1,a+n+1,cmp);
	dfs(0,0,0);
	cout << ans;
	return 0;
}
