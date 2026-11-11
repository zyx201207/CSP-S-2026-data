#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[1000000],sum=0;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int j=1;j<=n;j++){
	   for(int i=j+1;i<=n;i++){
	   if(a[i]&a[j]>sum)
	      sum=a[i]&a[j];
		}
	}
	cout<<sum;
return 0;
}
