#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1||n==1){
		cout<<a[n];
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=(a[i]|a[i-1]);
		}
		cout<<a[n];
	}else{
		
	}
	return 0;
} 
