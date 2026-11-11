#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,a[10000],maxx=0,maxi;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
			maxi=i;
		}
	}
	if(m==1){
		cout<<maxx;
	}
	else if(m==2){
		 maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(maxx<a[i]&a[j]){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
	}
	else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}else{
		int d;
		for(int i=1;i<=m;i++){	
			d=0;
			for(int j=1;j<=n;j++){
				if(maxx&a[j]>d&&maxi!=j){
					d=maxx&a[j];
				}
			}
		maxx=d;
		}
		cout<<maxx;
	}
	return 0;
} 
