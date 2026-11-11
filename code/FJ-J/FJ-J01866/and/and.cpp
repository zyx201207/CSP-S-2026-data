#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	if(m == 1){
		int Max = -1;
		for(int i = 1;i <= n;i++) {
			if(Max<a[i]){
				Max=a[i];
			}
		}
		cout<<Max;
		return 0;
	} 
	if(m == n){
		int x = a[1];
		for(int i = 2;i <= n;i++) {
			x=(x & a[i]);
		}
		cout<<x;
		return 0;
	}
	if(m == 2){
		int Max = -1;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(Max<(a[i] & a[j]) && i!=j){
					Max=(a[i] & a[j]);
				}
			}
		}
		cout<<Max;
		return 0;
	}  
	if(m == n-1){
		int Max = -1;
		for(int i = 1;i <= n;i++) {
			int x,y;
			if(i>1){
				x = a[1];
				y = 1;
			}else{
				x = a[2];
				y = 2;
			}
			for(int j = 1;j <= n;j++) {
				if(j != y && j != i){
					x=(x & a[j]);
				}
			}
			for(int j = 1;j <= n;j++) {
				if(Max<x){
					Max=x;
				}
			}
		}
		cout<<Max;
		return 0;
	}  
	return 0;
} 
