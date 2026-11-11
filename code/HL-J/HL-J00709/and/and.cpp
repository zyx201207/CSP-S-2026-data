#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max1=-1e9;
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		   a[i]=a[i]&a[j];	
		}
		max1=max(max1,a[i]);
	cout<<max1;
	return 0;
}
