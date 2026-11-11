#include<bits/stdc++.h> 
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=-100005;
	
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
		
	}else if(m==n){
		int y=a[1];
		for(int i=2;i<=n;i++){
		y&=a[i];
	}
		
		cout<<y;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ma=max(ma,a[i]&a[j]);
				
				
			}
			
		}
		
		
		cout<<ma;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				for(int k=1;k<j;k++){
				
				ma=max(ma,a[i]&a[j]&a[k]);
				}
				
			}
			
		}
		
		
		cout<<ma;
	}else if(m==4&&n<70){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				for(int k=1;k<j;k++){
					for(int o=1;o<k;o++){
					
				 ma=max(ma,a[i]&a[j]&a[k]&a[o]);
				                        }
				}
				
			}
			
		}
		
		
		cout<<ma;
	}else if(m==5&&n<50){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				for(int k=1;k<j;k++){
					for(int o=1;o<k;o++){
						for(int u=1;u<o;u++){
						 
				 ma=max(ma,a[i]&a[j]&a[k]&a[o]&a[u]);
				                       } }
				}
				
			}
			
		}
		
		
		cout<<ma;
	}else{
		sort(a+1,a+n+1);
		cout<<a[1];
		
	}
		
	
	
	return 0;
}
