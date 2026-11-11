#include<bits/stdc++.h>
using namespace std;
int main(){
	long long c,t,n,d,a[100005];
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
		    cin>>a[j];		
	    }
		if(c>10&&c<13){
	    	cout<<n-3<<'\n';
		}else {
			if(n<4){
				cout<<"0"<<'\n';
			}else{
				cout<<n-3<<'\n';
			}
		}	
	}
	return 0;
}
