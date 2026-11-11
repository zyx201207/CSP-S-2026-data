#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t,n,d,x[2000000],ans=0,abs=0;
	cin>>c>>t;
	

	for(int i=1;i<=t;i++){
	    cin>>n>>d;
	    for(int i=1;i<=n;i++) {
    		cin>>x[i];
    	}
    	for(int i=1;i<=n;i++){
    		if((x[i]+x[i+1])>=d){
    			abs++;
    			if(abs>=2){
    				ans++;
				}
			}
		}
		cout<<ans<<endl;
    }
	return 0;
}
