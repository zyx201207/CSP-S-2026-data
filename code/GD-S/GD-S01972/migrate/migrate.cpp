#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[500060];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	int n,d;cin>>n>>d;
    	int ans=0,p=1;
    	for(int j=1;j<=n;j++){
    		cin>>a[j];
    		if(a[j]-a[p]>d*2-1) p++;
    		if(a[j]-a[p]==d*2-1)  ans++;
    		
		}
		cout<<ans<<endl;
	}
	return 0;
}


