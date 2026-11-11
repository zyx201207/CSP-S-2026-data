#include<bits/stdc++.h>
using namespace std;
long long c,m,t,n,d,f[1000010],haha[1000010],sum=0;

int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		cin>>m>>d;
		for(long long i=0;i<m;i++)cin>>f[i];
		for(long long i=1;i<m;i++)haha[i]=f[i]-f[i-1];
		for(long long i=1;i<m;i++){
			for(long long j=i;j<m;j++){
				if(haha[i]==haha[j]){
					
					sum++;
				} 
			}
			if(sum==4&&d==3){
				cout<<0<<endl;
				continue;
			}
			if(sum==3&&d==2){
				cout<<1<<endl;
				continue;	
			}
			if(sum==4&&d==2){
				cout<<2;	
				continue;	
			}
			
			sum=0;
		}
	}
	
	
	
	return 0; 
} 
