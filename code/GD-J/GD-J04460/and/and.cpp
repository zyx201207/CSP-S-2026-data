#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long d=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>d){
				d=a[i];
			}
		}
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]&a[j]>d&&i!=j){
					d=a[i]&a[j];
				}
			}
		}
	}else {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(a[i]&a[j]&a[k]>d){
						d=a[i]&a[j]&a[k];
					}
				}
			}
		}
	}
	cout<<d;
	return 0;
}
