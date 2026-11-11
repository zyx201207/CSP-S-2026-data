#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],c[1000000];

int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	long long n,m,mi=-1,m1,he=0,ma=-1;
	cin>>n>>m;
	
	for(long long i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	
	for(long long i=0;i<n;i++){
		m1=m;
		he=0;
		
		for(long long j=0;j<n;j++){
			c[j]=a[i]-a[j];
			
				
				
				
				
		}
		 
		
		while(m1){
			 mi=9999999999999999;
		
	
			for(long long j=0;j<n;j++){
				cout<<c[j]<<' ';
				
				
				
				if(mi>=c[j] && c[j]>=0){
					
					mi=c[j];
					c[j]=-1;
				}
			}
			cout<<endl;
			//cout<<mi<<' ';
			
			if(m1>=mi){
				m1-=mi;
				he+=1;
			}
			else break;
		}
		//cout<<m1<<endl;
		//cout<<he<<endl;
		if(ma<he)ma=he;
		
		
	}
	cout<<ma;
	
	
	
	return 0;
} 
