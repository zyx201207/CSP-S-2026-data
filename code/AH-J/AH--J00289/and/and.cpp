#include<bits/stdc++.h>
using namespace std;
int n,a[200005],mx,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			cout<<mx;
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int h=k+1;h<=n;h++){
						mx=max(mx,a[i]&a[j]&a[k]&a[h]);
					}
				}
			}
		}
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			mx=mx&a[i];
		}
	}
	cout<<mx;
}
