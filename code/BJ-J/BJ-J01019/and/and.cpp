#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
long long andl[MAXN];
bool cmp(long long a,long long b){
	return a > b;
}
bool check(long long x){
	for(int i = 0;i < 21;i++){
		if(x != pow(2,i) - 1){
			return false;
		}
	}
	return true;
}
void solve1(int n,int m){
	sort(andl,andl + n,cmp);
	long long ans = andl[0] & andl[1];
	for(int i = 2;i < m;i++){
		ans &= andl[i];
	}
	cout<<ans;
}
void solve2(int n,int m){
	long long ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			ans = max(andl[i] & andl[j],ans);
		}
	}
	cout<<ans;
}
void solve3(int n,int m){
	long long ans = 0;
	for(int i = 0;i < n;i++){
		ans = max(andl[i],ans);
	}
	cout<<ans;
}
void solve4(int n,int m){
	long long ans = andl[0];
	for(int i = 1;i < n;i++){
		ans &= andl[i];
	}
	cout<<ans;
}
void solve5(int n,int m){
	long long maxn = -1;
	for(int i = 0;i < n;i++){
		long long ans;
		if(i == 0){
			ans = andl[1];
		}
		else{
			ans = andl[0];
		}
		for(int j = 0;j < n;j++){
			if(j == i){
				continue;
			}
			ans &= andl[j];
		}
		maxn = max(ans,maxn);
	}
	cout<<maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	bool flag = false;
	for(int i = 0;i < n;i++){
		cin>>andl[i];
		if(!check(andl[i])){
			flag = true;
		}
	}
	if(!flag){
		solve1(n,m);
	}
	else if(m == 2){
		solve2(n,m);
	}
	else if(m == 1){
		solve3(n,m);
	}
	else if(m == n){
		solve4(n,m);
	}
	else if(m == n - 1){
		solve5(n,m);
	}
	else{
		solve1(n,m);
	}
	return 0;
}