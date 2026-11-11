#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1e6,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			c=a[i]&0;
			maxx=max(maxx,c);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c=a[i]&a[j];
				maxx=max(maxx,c);
			} 
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i-1]&a[i];
		}
		cout<<a[n];
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					a[j]=a[j-1];
				}
				else{
					a[j]=a[j-1]&a[j];
				}
			}
		}
		cout<<a[n];
		return 0;
	}
	return 0;  
}
