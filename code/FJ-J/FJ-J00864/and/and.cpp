#include<bits/stdc++.h>
using namespace std;
int ma,n,x,m,a[200005];
bool f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=n-m;i>=1;i--){
		for(int j=1;j<m;j++){
			f=0;
			if(a[i+j]!=a[i]){
				f=1;
			}
		}
		if(!f){
			cout<<a[i];
			return 0;
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					x=a[i]&a[j];
					ma=max(ma,x&a[o]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
