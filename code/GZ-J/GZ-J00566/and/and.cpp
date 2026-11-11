//GZ-J00566  七星关东辰实验学校  袁若雪
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],z[n],Min=0,s[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		a[i]%=2;
		a[i]/=2;
	}
	for(int i=n;i>0;i--){
		z[i]=a[i];
	}
	sort(z,n+z);
	for(int i=0;i<m;i++){
		if(z[i]&z[i+1]>z[i]&z[i+1]){
			s[i]=z[i]&z[i+1];
		}
		Min=max(Min,s[i]);
	}
	cout<<Min;
	return 0;
}
