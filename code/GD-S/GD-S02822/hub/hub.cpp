#include<bits/stdc++.h>
using namespace std;
int main(){
	long long c,t,n[10],d[10],x[100005],y[100005];
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(long long j=1;j<=n[i]-1;j++){
		    cin>>x[j]>>y[j];		
	    }
	    cout<<n[i]%4;
	}	
	return 0;
}
