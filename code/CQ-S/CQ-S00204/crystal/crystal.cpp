#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int ans;
		for(int j=i;j<=m;j++){
			ans=a[i]-a[j];
			if(ans<=m){
				if(i-j+1>ans){
					ma+=i-j+1;
				}
			}
		}
	}
	cout<<ma;
	return 0;
	
} 
