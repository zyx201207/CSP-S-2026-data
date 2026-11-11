#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,b[200005],sum,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		k++;
		b[i]=a[i];
	//	cout<<b[i]<<" ";
	    for(int j=i-1;j>=i-m+1;j--){
	    	k++;
				b[i]&=a[j];
		}
		if(k>2e8){
		for(int j=1;j<=n;j++){
		    sum=max(sum,b[j]);
	    }
	    cout<<sum;
	    return 0;
		}
	}
	for(int i=1;i<=n;i++){
		sum=max(sum,b[i]);
	}
	cout<<sum;
	return 0;
}
/*
4 2
3 15 12 12
*/
