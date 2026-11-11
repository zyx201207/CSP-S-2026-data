#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],maxx=-100;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=maxx){
				maxx=a[i];
			}
		
		
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>=maxx){
					maxx=(a[i]&a[j]);
				}
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n-1;j++){
				if((a[i]&a[j]&a[j+1])>=maxx){
					maxx=(a[i]&a[j]&a[j+1]);
				}
			}
		}
	}
	
	if(m==4){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n-2;j++){
			if((a[i]&a[j]&a[j+1]&a[j+2])>=maxx){
				maxx=(a[i]&a[j]&a[j+1]&a[j+2]);
			}
		}
	}
	}	
	
	
	if(m==5){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n-2;j++){
			if((a[i]&a[j]&a[j+1]&a[j+2]&a[j+3])>=maxx){
				maxx=(a[i]&a[j]&a[j+1]&a[j+2]&a[j+3]);
			}
		}
	}
	}	
	
	cout<<maxx;
	
	
	
	
	return 0;
}
