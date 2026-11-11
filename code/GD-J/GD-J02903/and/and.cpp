#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		ma=0;
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else if(m==n){
		y=0x7fffffff;
		for(int i=0;i<n;i++){
			y=y&a[i];
		}
		cout<<y;
	}
	else if(m==n-1){
		y=0x7fffffff;
		ma=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j!=i) y=y&a[j];
			}
			ma=max(ma,y);
			y=0x7fffffff;
		}
		cout<<ma;
	}
	else if(m==2){
		y=0x7fffffff;
		ma=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j) ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	else if(m==m-2){
		y=0x7fffffff;
		ma=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(k!=i && k!=j && i!=j) y=y&a[k];
				}
				ma=max(ma,y);
			}
		}
		cout<<ma;
	}
	else cout<<0;
}
