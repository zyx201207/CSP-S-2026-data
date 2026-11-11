#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	if(m==2){
		for(int i=n;i>1;i--){
	      if(a[i]==a[i-1]){
	    	cout<<a[i];
	        return 0;
		  }
	    }
	}
	return 0;
}
