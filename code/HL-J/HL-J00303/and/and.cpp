#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,a[300000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int ma=0;
	if(m==1){
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		ma=a[0];
		for(int i=1;i<n;i++){
			ma=ma&a[i];
		}
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	int y=0,u=0;
	if(n-1==m){
		for(int i=0;i<n;i++){
			if(i==0){
				y=a[1];
			}else{
				y=a[0];
			}
			for(int j=1;j<n;j++){
				if(j!=i){
					y=y&a[j];
				}
			}
			ma=max(ma,y);
		}
		cout<<ma;
		return 0;
	}
	cout<<0;
	return 0;
}
