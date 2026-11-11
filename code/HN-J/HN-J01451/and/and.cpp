#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
    sort(a,a+n);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=i;j++){
    		if(a[j]<a[j+1])
    		swap(a[j],a[j+1]);
		} 
	}
	int sum=a[1];
	cout<<a[m]%sum;
	return 0;
} 
