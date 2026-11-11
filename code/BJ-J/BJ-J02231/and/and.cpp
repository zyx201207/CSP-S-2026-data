#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==1){
		int x=0;
		for(int i=1;i<=n;++i){
			if(a[i]>x)
			x=a[i];
		}
		cout<<x;
	}
	if(m==2){
		int x=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if((a[i]&a[j])>x)
				x=a[i]&a[j];
			}
		}
		cout<<x;
	}
	if(m==3){
		int x=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					if((a[i]&a[j]&a[k])>x)
					x=a[i]&a[j]&a[k];
				}
			}
		}
		cout<<x;
	}
	if(m==4){
		int x=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					for(int q=k+1;q<=n;++q){
						if((a[i]&a[j]&a[k]&a[q])>x)
						x=a[i]&a[j]&a[k]&a[q];
					}
				}
			}
		}
		cout<<x;
	}
	if(m==5){
		int x=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					for(int q=k+1;q<=n;++q){
						for(int p=q+1;p<=n;++p){
							if((a[i]&a[j]&a[k]&a[q]&a[p])>x)
							x=a[i]&a[j]&a[k]&a[q]&a[p];
						}
					}
				}
			}
		}
		cout<<x;
	}
	else if(m==n){
		int x=a[1];
		for(int i=1;i<=n;++i){
			x=x&a[i];
		}
		cout<<x;
	}
	return 0;
}
