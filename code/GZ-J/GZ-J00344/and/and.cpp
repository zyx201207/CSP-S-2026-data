//GZ-J00344  遵义市第十九中学 丁钧泽 
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
	}else if(m==n){
		s=a[1]&a[2];
		for(int i=3;i<=n;i++){
			s=s&a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(a[i]&a[j],s);
			}
		}
	}
	cout<<s;
	return 0;
} 
