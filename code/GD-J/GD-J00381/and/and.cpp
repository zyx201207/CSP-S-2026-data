#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],zo,mi,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	
    	ans=max(ans,a[i]);
	}
	if(m==1){
	cout<<ans;
	return 0;}
	if(m==n){
		for(int i=1;i<n;i++){
			a[i] =a[i]&a[i-1] ;
		}
		cout<<a[n];
		return 0;
	}
    sort(a,a+n);
    int ans =0;
    for(int i=n-m+1;i<n;i++){
    	a[i]=a[i]&a[i-1];
	}
    cout<<a[m-1];
	
    
	
	
	return 0;
} 
