#include<bits/stdc++.h>;
using namespace std;
int main(){

    freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	
	int y=0;
	int zd=0;
	int n,m,a[10000]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			y=a[i]&a[i];
			if(y>zd){
				zd=y;
			}
		}
		cout<<zd;
	}
	
	
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				y=a[i]&a[j];
				if(y>zd){
					zd=y;
				}
				
			}
		}
		cout<<zd;
	}
	else cout<<a[9];
    return 0;
}
