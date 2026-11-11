#include<bits/stdc++.h>
using namespace std;
const int num = 2e5+5;
long long a[num];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long max_ = -1;
	long long all;
	int max_k = -1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		max_ = max(max_,a[i]);
		if(i==1){
			all = a[i];
		}else{
			all &= a[i];
		}
	}
	if(m==1){
		cout << max_;
		return 0;
	}
	if(m==n){
		cout << all;
		return 0;
	}
	if(m==n-1){
		long long max_1 = a[2];
		long long max_2 = a[1];
		for(int i=2;i<=n;i++){
			if(i==2){
				max_2 &= a[i];
			}else if(i==n){
				max_1 &= a[i];
			}else{
				max_1 &= a[i];
				max_2 &= a[i];
			}
		}
		cout << max(max_1,max_2);
		return 0;
	}
	if(m==2){
		long long max_ans = -1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max_ans = max(max_ans,a[i]&a[j]);
			}
		}
		cout << max_ans;
		return 0;
	}
	sort(a+1,a+n+1,greater<long long>());
	long long max_ans = a[1];
	for(int i=2;i<=m;i++){
		max_ans &= a[i];
	}
	cout << max_ans;
	return 0;
} 
