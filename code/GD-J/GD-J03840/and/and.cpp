#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma=-1,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		y=a[1];
		for(int i=1;i<=n;i++){
			y=y&a[i];
			ma=y;
		}
		cout<<ma;
		return 0;		
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
		cout<<ma;
		return 0;		
	}
	if(n-m==1){
		y=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				else y=y&a[j];
			}
			if(y>ma){
				ma=y;
			}
			y=a[i];
		}
		cout<<ma;
		return 0;		
	}	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				y=y&a[j];
				if(y>=ma){
					ma=y;
				}
			}
			y=a[i];	
		}
		cout<<ma;
		return 0;		
	}	
	return 0;
}
