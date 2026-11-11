#include<bits/stdc++.h>
using namespace std;

int c,t;


		

int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
	while(t--){
		
		
		int n,d,cnt=0;
		int x[2000005];
		cin>>n>>d;
		
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=2;j<n;j++)
			if(  !(x[j]-x[i]<=d) ) 
			cnt++;
		}
		cout<<cnt+1<<endl;
		
		
		
		
		
	}
	
	
	return 0;
}
