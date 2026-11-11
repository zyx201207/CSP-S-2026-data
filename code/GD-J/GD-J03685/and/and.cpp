#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;long long mx=0;
int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
	}
	int l=0;
	if(m==n){
		int g=a[0];
		for(int i=1;i<n;i++){
			g&=a[i];
		}
		cout<<g;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>mx)mx=a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		int l=0,r=1;
		while(1){
			int g=a[l]&a[r];
			if(g>mx)mx=g;
			r++;
			if(r==n-1){
				l++;
				r=l+1;
			}
			if(l==n-2) break;
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		bool vis[200005];
		int l=0;
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		vis[l]=1;
		if(l!=0){
			int g=a[0];
			for(int i=1;i<n;i++){
				if(!vis[i])g&=a[i];
			}
			if(g>mx)mx=g;
		}
		else{
			int g=a[1];
			for(int i=2;i<n;i++){
				g&=a[i];
			}
			if(g>mx)mx=g;
		}
		cout<<mx;
		return 0;
	}
	while(1){
		int h=0;
		int g=a[l];
		for(int i=l+1;i<n;i++){
			h++;
			g&=a[i];
			if(h==m-1) break;
		}
		if(g>mx)mx=g;
		if(n-l-1<m) break;
		l++;
	}
	cout<<mx;
	return 0;
}
