#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ma=0;
	if(m==1){
		sort(a,a+n);
		cout<<a[n];
		return 0;
	}else if(m==2){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int sum=a[i]&a[j];
			ma=max(ma,sum);
		}
	}
	cout<<ma;
	return 0;
}else if(m==3){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
			int sum=a[i]&a[j]&a[k];
			ma=max(ma,sum);
			}
		}
	}
	cout<<ma;
	return 0;
}else if(m==4){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
			int sum=a[i]&a[j]&a[k]&a[l];
			ma=max(ma,sum);
				}
			}
		}
	}
	cout<<ma;
	return 0;
}else if(m==5){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
					for(int r=l+1;r<n;r++){
			int sum=a[i]&a[j]&a[k]&a[l]&a[r];
			ma=max(ma,sum);
					}
				}
			}
		}
	}
	cout<<ma;
	return 0;
}
	return 0;
}
