#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,maxn;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(m == 1){
		maxn = a[1];
		for(int i = 2;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m == 2){
		maxn = a[1] & a[2];
		for(int i = 1;i <= n;i++){
			for(int j = 3;j <= n;j++){
				int t = 0;
				t = a[i] & a[j];
				maxn = max(maxn,t);
			}
		} 
		cout<<maxn;
		return 0;
	}
	else if(m == n){
		maxn = a[1];
		for(int i = 2;i <= n;i++){
			maxn = maxn & a[i]; 
		}
		cout<<maxn;
		return 0;
	}
}
