#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	long long a[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	long long s=-2;
	long long h=-1;
	int k=n;
	while(h>s&&k-m>=0){
		s=h;
		h=a[k];
		for(int i=k;i>k-m+1;i--){
			h=a[i]&a[i-1];
		}
		k--;
	}
	cout<<s;
	
	return 0;
}
