#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c,t;
	for(int u=0;u<t;u++){
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int p=0;
		int o=0;
		for(int i=0;i<n-1;i++){
			int q=0,w=0;
			
			if(a[i]<0){
				q=a[i]-a[i]-a[i];
			}else{
				q=a[i];
			}
			if(a[i+1]<0){
				w=a[i+1]-a[i+1]-a[i+1];
			}else{
				w=a[i+1];
			}
			max(p,max(q,w)-min(q,w));
			if(p>d){
				o=1; 
			}
		}if(o){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
		
	}
	
	return 0;
} 
