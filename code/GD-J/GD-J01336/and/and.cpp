#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5]; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=a[n];
	for(int i=n-1;i>m;i--){
		if(a[i]<sum){
			sum=a[i];
		}
	}
	cout<<sum;
	return 0;
}
