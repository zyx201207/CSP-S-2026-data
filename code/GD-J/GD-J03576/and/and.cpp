#include<bits/stdc++.h>
using namespace std;
int a[700000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn = -1e9;
		for(int i = 1;i<=n;i++){
			if(a[i]>maxn){
				maxn = a[i];
			}
		}
		cout<<maxn;
	}else if(m==2){
		int maxn = -1e9;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(a[i]&a[j]>maxn){
					maxn = a[i]&a[j];
				}
			}
		}
		cout<<maxn; 
	}else if(m==3){
		int maxn = -1e9;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				for(int i1 = j+1;i1<=n;i1++){
					if(a[i]&a[j]&a[i1]>maxn){
						maxn = a[i]&a[j]&a[i1];
					}
				}
				
			}
		}
		cout<<maxn; 
	}
	
	
	

	return 0;
}

