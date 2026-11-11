#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("and.in","r",stdin);
	preopen("and.out","w",stdout);
	int n,m,a[1000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	   cin>>a[i];
	}
	sort(a,a+n);
	int d=m;
	for(int i=n-1;i>=1;i++){
	   if(d==0){
	   	 break;
	   }
	   a[i]=a[i+1]&&a[i];
	   d--;
	}
	cout<<a[n-m];
	return 0;
}
