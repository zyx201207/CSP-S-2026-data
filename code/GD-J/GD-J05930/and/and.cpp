#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			x=min(x,a[i]);
		}
		cout<<x;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			x=max(x,a[i]);
		}
		cout<<x;
		return 0;
	}
	else if(m==2){
		sort(a,a+n+1);
		cout<<a[2];
		return 0;
	}
	else sort(a,a+n+1);
	
	cout<<a[m];
	return 0;
} 
