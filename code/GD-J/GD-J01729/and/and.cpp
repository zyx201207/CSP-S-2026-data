#include<bits/stdc++.h> 
using namespace std;
long long n,m,i,j,a[200005]; 
int main(){
	
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	long long maxx=0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	} 
	cout<<maxx;
	return 0;
}
