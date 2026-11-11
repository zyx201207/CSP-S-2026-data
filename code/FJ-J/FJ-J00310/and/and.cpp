#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,max_=0,m;
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=n;i++){
			max_+=a[i]&a[i+1];
		}
		cout<<max_;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			max_=max(a[i]&a[j],max_);
		}
	}
	cout<<max_;
	return 0;
} 
