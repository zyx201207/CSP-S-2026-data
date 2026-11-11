#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(m==1){
		sort(b+1,b+n+1);
		cout<<b[n];
	}
	if(m==n){
		y=a[1];
		for(int i=2;i<=n;i++){
			y=y&a[i];
		}
		cout<<y;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>=y){
					y=a[i]&a[j];
				}
			}
		}
		cout<<y;
	}
	int maxx=0;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			y=a[1];
			for(int j=1;j<=n;j++){
				if(i==1)
					y=a[2];
				if(j!=i)
					y=y&a[j];
			}
			maxx=max(y,maxx);
		}
		cout<<maxx; 
	}
	return 0;
} 
