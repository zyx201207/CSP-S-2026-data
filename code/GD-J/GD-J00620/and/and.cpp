#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=0;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ma=max((a[i]&a[j]),ma);
			}
		}
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					ma=max((a[i]&a[j]&a[z]),ma);
				}
			}
		}
	}
	cout<<ma;
	return 0;
}
