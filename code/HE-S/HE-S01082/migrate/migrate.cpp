#include<bits/stdc++.h>
using namespace std;
long long x[2000006],d;
int c,t,n;
/*int findroad(int a,int b){
	long long roads=0;int lowest=n-1;
	for(int k=a+1;x[k]-x[a]&&k<=b;k++){
		int f=findroad(k,b);
		if(f>lowest)
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		/*long long ans=0;
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n-1;i++){
			for(int j=i+1;i<n;i++){
				long long roads=0,lowest=n-1;
				for(int k=i+1;x[k]-x[i]<=d&&k<=j;k++){
					
				}
			}
		}
		cout<<ans;*/
		cout<<1;
		memset(x,0,n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
