#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen(crystal.in,"w",stdin);
    freopen(crystal.out,"r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i]++;
			m--;
			if(a[i]==a[i+1]){
				sum++;
			}
			if(m==0){
				cout<<sum+1;
			}
		}
	}
	return 0;
}
