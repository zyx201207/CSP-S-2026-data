#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long last[500005];//表示第i个元素的最近后缀
long long ans[300005];
long long cnt[300005];
bool check_b(){
	long long idx;
	for(int i=1;i<n;i++){
		if(a[i]==a[n]){
			idx=i;
		}
		cnt[a[i]]++;
		if(cnt[a[i]]>1) return false;//重复 
	}
	for(int i=1;i<idx;i++){
		ans[a[i]]=i;
	}
	ans[a[n]]=n;
	for(int i=idx+1;i<n;i++){
		ans[a[i]]=i-idx;
	}
	return true;
}
void solve_b(){
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check_b()){
		solve_b();
		return 0;
	}
	for(int i=n;i>=1;i--){//O(n^2)~O(n)
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				last[i]=last[j];
				break;
			}
		}
		if(last[i]==0){
			last[i]=i;
		}
	}
	for(int i=1;i<=n;i++){//如果出现n=m，且a_i!=a_j，则退化为O(n) 
		long long idx=i;
		while(idx<=n){
			while(last[idx]!=idx){
				idx=last[idx];
			}
			ans[a[idx]]++;
			idx++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
