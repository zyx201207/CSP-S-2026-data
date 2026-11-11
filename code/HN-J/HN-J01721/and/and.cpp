#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0,maxx1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx1=max(maxx1,(a[i]&a[j]));
			}
		}
		cout<<maxx1;
		return 0;
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<=n;z++){
					maxx1=max(maxx1,(a[i]&a[j]&a[z]));	
				}
			}
		}
		cout<<maxx1;
		return 0;
	}
	if(m==4){
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int z=j+1;z<n;z++){
					for(int x=z+1;x<=n;x++){
						maxx1=max(maxx1,(a[i]&a[j]&a[z]&a[x]));
					}
				}
			}
		}
		cout<<maxx1;
		return 0;
	}
	if(m==5){
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int z=j+1;z<n-1;z++){
					for(int x=z+1;x<n;x++){
						for(int y=x+1;y<=n;y++){
							maxx1=max(maxx1,(a[i]&a[j]&a[z]&a[x]&a[y]));
						}
					}
				}
			}
		}
		cout<<maxx1;
		return 0;
	}
	return 0;
} 
