#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int a[10000];
		int n,e;
		cin>>n>>e;
		for(int i=0;i<n;i++){
	        cin>>a[i]; 
		}
        int d=(a[2]-a[1]);
        int ans=0;
        if(e>=2*d){
        	for(int i=0;i<n;i++){
        		if(i+4<=n)ans++;
			}
			cout<<ans<<endl;
		}
		else {
		  cout<<0<<endl;
	   }
	}
	return 0;
}
