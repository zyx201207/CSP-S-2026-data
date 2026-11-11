#include<bits/stdc++.h>
using namespace std;
long long m,n,a[300020],maxa=-1111;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==n){
		maxa=a[1];
		for(int i=2;i<=n;i++){
			maxa=maxa&a[i];
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(a[i]&a[j],maxa);
			}
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxa=max(a[i]&a[j]&a[k],maxa);
				}
			}
		}
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int f=k+1;f<=n;f++){
						maxa=max(a[i]&a[j]&a[k]&a[f],maxa);
					}
				}
			}
		}
	}cout<<maxa;
	return 0;
}
