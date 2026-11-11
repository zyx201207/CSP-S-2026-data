#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)
	int m,n,a[1000],max=-10000;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
	 cin>>a[i];
}
	  for(int j=1;j<=n;j++)
	  for(int k=1;k<=j;k++)
	    if(a[j] and a[k]>max)
	    max=a[j] and a[k];
	cout<<max;    
	return 0;
} 
