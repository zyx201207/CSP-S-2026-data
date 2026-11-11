#include <bits/stdc++.h>
using namespare std;
int abc(int x,int y){
	if(x>y){
		return x;
	}
	if(x==y){
		return x;
	}
	if(x<y){
		return y
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[100005],b[100005],c[100005],d[100005],cnt=0;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				int x=a[i];
				int y=a[j];
				int z=abc(x,y);
				while(x>0){
					b[i]=x%2;
					x/=2;
				}
				while(y>0){
					c[i]=y%2;
					y/=2;
				}
				for(int i=1;i<=z;i++){
					if(b[z]==1&&c[z]==1){
						d[z]=1;
					}
					else{
						d[z]=0;
					}
				}
				for(int i=1;i<=z;i++){
					for(int i=1;i<=z;i++){
						d[z]*2; 
					}
					cnt+=d[z];
				}
					
				}
				
			}
			
		}
	}
	cout<<cnt;
	return 0;
}
