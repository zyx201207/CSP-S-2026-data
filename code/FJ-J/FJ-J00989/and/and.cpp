#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int a[20005];

int main()

{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i = 0;i<n;i++){
			int l;
			cin>>l;
			maxn=max(maxn,l);
		}
		cout<<maxn;
	}
	else if(n==m){
		int l;
		cin>>l;
		maxn=l;
		for(int i = 1;i<n;i++){
			cin>>l;
			maxn=maxn&l;
		}
		cout<<maxn;
	}
	else if(m==2){
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==3){
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					maxn=max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxn;
	}
	else if(m==4){
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<n;k++){
					for(int l = k+1;l<n;l++){
						maxn=max(maxn,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
