//GZ-J00523 зѓгІКщ КывужабЇ 
#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
char c[50];
int main(){
	freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	long long n,k=0,l=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
     if(n%2==0&&c[i]!=c[n+1-i]){
      k=min(a[i],a[n+1-i])+k;
     	 
	 }else if(n%2!=0&&c[i]!=c[n-i]){
	 	k=min(a[i],a[n-i])+k;
	 	
	 } 

	}
	cout<<k<<'\n'; 
	return 0;
} 
