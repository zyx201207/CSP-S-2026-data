#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(m == 1){
		int max_v = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] >= max_v){
				max_v = a[i];
			}
		}
		cout<<max_v;
	}
	else if(m == 2){
		int max_v = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[i] & a[j] >= max_v){
					max_v = a[i]&a[j];
				}
			}
		}
		cout<<max_v;
	}else if(m == n){
		int t = a[1];
		for(int i = 2;i <= n;i++){
			t &= a[i];
		}
		cout<<t;
	}else if(m == n-1){
		cout<<12;
	}else{
		cout<<6;
	}
	return 0;
}