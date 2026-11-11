#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],t=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			t=max(t,a[i]&0);
		}
	}
	else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=1+i;j<n;j++){
				t=max(a[j] & a[i],t);
			}
		}
	}
	else if(m==3){
		for(int i=0;i<n-2;i++){
			for(int j=1+i;j<n-1;j++){
				for(int z=1+j;z<n;z++){
					t=max(a[i]&a[j]&a[z],t);
				}
			}
		}
	}
	else if(m==4){
		for(int i=0;i<n-3;i++){
			for(int j=1+i;j<n-2;j++){
				for(int z=1+j;z<n-1;z++){
					for(int x=1+j;x<n;x++){
						t=max(a[i]&a[j]&a[z]&a[x],t);
					}
				}
			}
		}
	}
	else if(m==5){
		for(int y=0;y<n-4;y++){
			for(int i=1+y;i<n-3;i++){
				for(int j=1+i;j<n-2;j++){
					for(int z=1+j;z<n-1;z++){
						for(int x=1+j;x<n;x++){
							t=max(a[y]&a[i]&a[j]&a[z]&a[x],t);
						}
					}
				}
			}
		}	
		
	}
	else if(m==6){
		for(int c=0;c<n-5;c++){
			for(int y=1+c;y<n-4;y++){
				for(int i=1+y;i<n-3;i++){
					for(int j=1+i;j<n-2;j++){
						for(int z=1+j;z<n-1;z++){
							for(int x=1+j;x<n;x++){
								t=max(a[c]&a[y]&a[i]&a[j]&a[z]&a[x],t);
							}
						}
					}
				}
			}	
		}
		
	}
	cout<<t;
	  
	return 0;
}
