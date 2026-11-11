#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long p[30],ma;
long long l[200010],r[200010];
long long a[200010],maxn = 0;
int n,m;
void dfs(int step,int num,long long ans){
	if(step > n) maxn = max(maxn,ans);
	else if(step > n - m + num) dfs(step + 1,num + 1,ans & a[step]);
	else{
		dfs(step + 1,num,ans);
		dfs(step + 1,num + 1,ans & a[step]);
	}
}
bool pw(){
	for(int i = 1;i <= n;i++){
		bool flag = false;
		if(a[i] == 0) continue;
		for(int j = 0;j <= 20;j++){
			if(a[i] == p[j] || a[i] == 0){
				flag = true;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= 20;i++) p[i] = pow(2,i) - 1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		ma = max(ma,a[i]);
	}
	if(m == 1){
		sort(1 + a,1 + a + n);
		cout<<a[n];
		return 0;
	}else if(m == n){
		long long  x = a[1];
		for(int i = 2;i <= n;i++) x = (x & a[i]);
		cout<<x;
		return 0;
	}else if(m == 2){
		long long maxx = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j) maxx = max(maxx,(a[i] & a[j]));
		cout<<maxx;
		return 0;
	}else if(n == m + 1){
		l[1] = a[1];
		r[1] = a[n];
		for(int i = 2;i <= n;i++) l[i] = (l[i - 1] & a[i]);
		for(int i = n - 1;i >= 1;i--) r[n - i + 1] = (r[n - i] & a[i]);
		for(int i = 2;i < n;i++) maxn = max(maxn,(l[i - 1] & r[n - i]));
		maxn = max(maxn,r[n - 1]);
		cout<<max(maxn,l[n - 1]);
	}else if(ma < 4){
		sort(1 + a,1 + a + n);
		int length1 = 0,length2 = 0,length3 = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) length1++;
			if(a[i] == 2) length2++;
			if(a[i] == 3) length3++;
		}
		if(length3 >= m) cout<<3;
		else if(length2 + length3 >= m) cout<<2;
		else cout<<0;
		return 0;
	}
	if(pw()){
		sort(1 + a,1 + a + n);
		cout<<a[n - m + 1];
		return 0;
	}
	dfs(1,0,1.07374e+09 - 1);
	cout<<maxn;
	
	return 0;
}
