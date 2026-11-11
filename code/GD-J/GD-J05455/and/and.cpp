#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		int res=0;
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			res=cnt;
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==2){
		int mx=-99999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
	}
	else if(m==3){
		int mx=-99999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j and i!=k and j!=k)mx=max(a[i]&a[j]&a[k],mx);
				}
			}
		}
		cout<<mx;	
	}
	else if(m==3){
		int mx=-99999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j and i!=k and j!=k)mx=max(a[i]&a[j]&a[k],mx);
				}
			}
		}
		cout<<mx;	
	}
	else if(m==1){
		int mx=-99999;
		for(int i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;	
	}
	return 0;
} 
