#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int f[2000006];
int en=1e9;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
	long long ans=0;
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;n>=i;i++){
			cin>>x[i];
		}
		
	    for(int i=1;n>=i;i++){
	    	f[x[i]]=f[x[i]+d]=f[x[i]+2*d]=1;
	    	if(x[i]+d<x[i+1]){
	    		en=min(en,i+1);
			}
	}
	for(int i=1;n>=i;i++){
		if(f[x[i]]!=1&&i!=en)ans++;
	}
	
	cout<<ans<<"\n";
	ans=0;}
	return 0;
 
}
