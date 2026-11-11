#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}	
	if(m==1){
		cout<<maxn;
	}else if(m==2){
		int maxn2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn2=max(maxn2,a[i]&a[j]);
				}
			}
		}
		cout<<maxn2;
	}else if(m==3){
		int maxn2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					if(i!=j&&i!=l&&j!=l){
						maxn2=max(maxn2,a[i]&a[j]&a[l]);
					}
				}
			}
		}
		cout<<maxn2;
	}
	return 0;
} 

