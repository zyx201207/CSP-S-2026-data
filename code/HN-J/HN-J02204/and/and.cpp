#include<bits/stdc++.h>
using namespace std;
int a[2000005],n,m,i,j;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		} 
	}
	cout<<a[m];
	return 0;	
}
