#include<bits/stdc++.h>
using namespace std;
long long a[300000];
int vis[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	bool num=1;
	long long r=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<=30;j++){
		int ans=0;
		for(int i=0;i<n;i++){
			if(vis[i]) continue;
			if((a[i]>>(30-j)) %2 == 1) ans++;
			else vis[i]++;
		}
	 	if(ans>=m){
	 		num=0;
	 		long long r1,i=0;
	 		while(1){
	 			if(vis[i]==0){
	 				r1=a[i];
	 				break;
				}
				i++;
			}
			for(int k=0;k<m-1;k++){
				i++;
				while(1){
	 				if(vis[i]==0){
	 					r1=r1&a[i];
	 					break;
					}
					i++;
				}
			}
			r=max(r,r1);
		}
		else if(num){
			for(int i=0;i<300000;i++){
	 			vis[i]=0;	
			}
		}
	}
	cout<<r;
	return 0;
} 
