#include <bits/stdc++.h>
using namespace std;
int ans,n,m,a[200000],b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			for(int k=j-1;k>=0;k--){
				if((a[i]&a[j]&a[k])>ans) ans=a[i]&a[j]&a[k];
			}
		}
	}
	cout<<ans;
	return 0;
} 

