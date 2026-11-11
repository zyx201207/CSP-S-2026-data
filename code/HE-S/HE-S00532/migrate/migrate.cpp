#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1100000]={0};
int can=0;
int mind=9999999;
int mindl=0;
void f(int l,int r,int k,int all){
	if(l==r){
		if(all<mind){
			mindl=1;
			mind=all;
		}
		else if(mind==all){
			mindl++;
		}
		return;
	}
	for(int i=l+1;i<=r;i++){
		if((a[i]-a[l])<=k){
			f(i,r,k,all+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
 	for(int i=1;i<=t;i++){
 		int n,d;
 		cin>>n>>d;
 		for(int i=1;i<=n;i++){
 			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				f(i,j,d,0);
				if(mindl==2){
					can++;
				}
				mindl=0;
				mind=9999999;
			}
		}
		cout<<can<<'\n';
		can=0;
	}
	return 0;
} 
