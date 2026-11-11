#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
	}
	else if(m==3){
		for(int k=1;k<=n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j||j==k||i==k) break;
					ma=(ma,a[i]&a[j]&a[k]);
				}
			}
		}
		
	}
	else{	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) break;
				ma=(ma,a[i]&a[j]);
			}
		}
	}
	cout<<ma;
	return 0;
}
