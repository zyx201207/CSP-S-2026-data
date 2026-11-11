#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[111111];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m==n){
		int sum=a[0];
		for(int i=1;i<n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==2){
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					int nn=a[i]&a[j];
					if(nn>=num){
						num=nn;
					}
				}
			}
		}
		cout<<num;
	}
	else if(m==3){
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(i!=j&&j!=k&&i!=k){
						int nn=a[i]&a[j]&a[k];
						if(nn>=num){
							num=nn;
						}
					}
				}	
			}
		}
		cout<<num;	
	}
	else if(m==4){
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
				    for(int h=0;h<n;h++){
				    	if(i!=j&&j!=k&&i!=k&&h!=i&&h!=k&&h!=j){
							int nn=a[i]&a[j]&a[k]&a[h];
							if(nn>=num){
							num=nn;
							}
						}
					} 
					
				}	
			}
		}
		cout<<num;	
	}
	else if(m==5){
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
				    for(int h=0;h<n;h++){
				    	for(int g=0;g<n;g++)
				    	if(i!=j&&j!=k&&i!=k&&h!=i&&h!=k&&h!=j&&h!=g&&g!=j&&g!=k&&g!=i){
							int nn=a[i]&a[j]&a[k]&a[h]&a[g];
							if(nn>=num){
							num=nn;
							}
						}
					} 
					
				}	
			}
		}
		cout<<num;	
	}
	else cout<<2;
	return 0;
}
