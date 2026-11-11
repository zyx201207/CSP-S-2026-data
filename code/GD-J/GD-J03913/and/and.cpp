#include<bits/stdc++.h>
using namespace std;
long long a[1234567],x[66666666],xxx;
int ad(long long mx,int y,int d,int b){
	if(y==0){
		for(int i=1;i<=d;i++)mx=max(mx,x[i]);
		return mx;
	}
	if(y==1)
	for(int i=1;i<=d;i++){
		for(int j=i+1;j<=d;j++){
			x[b]=x[i]&x[j];			
			++b;
		}
	}	
	d=b;
	if(d>111111111)return 0; 
	return ad(mx,y-1,d,0);
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,w;
	long long mx;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i];
	}
	if(n==1){
		cout<<a[1];
	}else if(m==1){
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}				
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++)mx=max(mx,a[i]&a[j]&a[k]);
			}
		}		
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						mx=max(mx,a[i]&a[j]&a[k]&a[l]);
					}							
				}
			}
		}		
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							mx=max(mx,a[i]&a[j]&a[k]&a[l]);
						}
					}			
				}
			}
		}		
	}else {
		mx=ad(mx,m,n,0);
	}
	cout<<mx;
	return 0;
}
