#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
	ll i,j,l,v,w,n,m,mx=0,x=0,a[201000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==0){
			x=a[i];
		}else{
			x&=a[i];
		}
	}
	if(m==1){
		cout<<mx;
		return 0;
	}if(m==n){
		cout<<x;
		return 0;
	}if(m==2){
		mx=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}if(m==3){
		mx=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(l=j+1;l<n;l++){
					mx=max(mx,a[i]&a[j]&a[l]);
				}
			}
		}
		cout<<mx;
		return 0;
	}if(m==4){
		mx=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(l=j+1;l<n;l++){
					for(v=l+1;v<n;v++){
						mx=max(mx,a[i]&a[j]&a[l]&a[v]);
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}if(m==4){
		mx=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(l=j+1;l<n;l++){
					for(v=l+1;v<n;v++){
						for(w=v+1;w<n;w++){
							mx=max(mx,a[i]&a[j]&a[l]&a[v]&a[w]);
						}
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
}
