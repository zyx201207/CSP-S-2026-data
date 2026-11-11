#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[20005],b[20005];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	   cin>>a[i];
	}
	if(m==1){
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=p){
				p=a[i];
			}
		}
		cout<<p;
		return 0;
	}
	if(m==n){
		int p=a[1];
		for(int i=2;i<=n;i++){
			p=(p&a[i]);
		}
		cout<<p;
		return 0;
	}
	
	if(m==(n-1)){
		int p=1,o=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					p*=a[j];
				}
			}
			if(p>=o){
				o=p;
			} 
		}
		cout<<o;
		return 0;
	}
	int p=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i&&(a[i]&a[j])>p){
				    	p=(a[i]&a[j]);
				}
				
			}
	  }
	cout<<p;
	return 0;
}
