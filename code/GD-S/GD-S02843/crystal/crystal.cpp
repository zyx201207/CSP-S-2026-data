#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long Max=1;
	long long n,m;
	long long num;
	cin>>n>>m;
	long long a[n+5];
	long long ans[n+5]={0};
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);
	long long mid;
	mid=n/2;
	num=a[mid];
	if (m!=0){
		for (int j=mid;j<=n;j++){
	    	for (int i=mid-1;i>=0;i--){
		 	    while (a[i]<a[mid]){
		 	   		a[i]++;
		 	   		m--;
				    if (m<=0){
				    	break;
					}
				}
			}
			for (int k=0;k<n;k++){
				if (a[k]==num){
					ans[j]++;
				}
			}
			if (ans[j]>=Max){
				Max=ans[j];
			}
			if (ans[j]<ans[j-1]){
				break;
			}
		}
		cout<<Max;
	}
	else{
		cout<<"1";
	}
}
