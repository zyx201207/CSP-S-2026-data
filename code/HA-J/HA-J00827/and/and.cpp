#include<bits/stdc++.h>
using namespace std;
int m[100000];
int y[100000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)
	
	int n;
	cin>>n;
	int a;
	int p;
	cin>>p;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a>0){
			m[i]=m[i]*10+a%2;
			a=a/2;
			
		}
		m[i]=m[i]*10+a;
	}
	int k;
	for(int i=1;i<=n;i++){
		for(int o=i+1;o<=n;o++){
			int e=m[i],z=m[o];
			while(min(e,z)>0){
				if(e%10==z%10){
					y[o]=y[o]*1*2;
				}
				if(e%10!=z%10){
					y[o]=y[o]*2+0;
				}
				e=e/10;
				z=z/10;
			}
			;
			int r;
			while(true){
				if (y[i]>y[i-1]){
					a=y[i];
					y[i]=y[i-1];
					y[i-1]=a;
				}
				else{
					break;
				}
			}
			
			k+=o;
		}
		
	}
	for(int i=k-1;i>0;i--){
		 
		if(y[i]==y[i-p+1]){
			cout<<y[i];
			break;
		}
	}
}
