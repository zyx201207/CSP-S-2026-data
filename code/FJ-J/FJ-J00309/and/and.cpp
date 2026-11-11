#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[20202];
int ans1,ans[20202];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			int e=a[i];
			for(int j=i+1;j<=n;j++){
				ans[i]=max(e&a[j],ans[i]);
			}
		}
		sort(ans+1,ans+1+n);
		cout <<ans[n];
	}
	else if(n==m){
		ans1=a[1];
		for(int i=2;i<=n;i++){
			ans1=ans1&a[i];
		}
		cout <<ans1;
	}
	else if(m==1){
		sort(a+1,a+1+n);
		cout <<a[n]; 
	}
	else cout <<0;
	return 0;
}
