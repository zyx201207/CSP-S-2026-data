#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m, y = 1, d = 100005, num = 0,mum = 0;
	cin>>n>>m;
	int a[10005];
	int u = a[n/2];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int h = 1;h<=n;h++){
				if(a[h]>a[h+1]){
					int k = a[h];
					a[h] = a[h+1];
					a[h+1] = k;
				}
			}
		}
	}
	for(int j = 1;j<=n;j++){
		if(num>mum)mum = num;
		while(y<=m){
			for(int i = 1;i<=n;i++){
				for(int h = 1;h<=n;h++){
					if(a[i]+h==u&&a[i]+h<=d){
						y+=h;
						a[i]+=h;
						d = a[i]+=h;
						num++;	
						continue;
					}
					else if(a[i]+h>u){
						continue;
					}
				}
			}
		}
	}
	cout<<num;
	return 0;
}
