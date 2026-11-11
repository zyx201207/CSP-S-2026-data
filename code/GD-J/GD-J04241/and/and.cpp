#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,f[25][25];
void s12345(){
	for(int i=1;i<=n;i++){
		f[1][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			for(int k=i-1;k<=j-1;k++){
				f[i][j]=max(f[i][j],f[i-1][k]&a[j]);
			}
		}
	}
	int x=0;
	for(int i=m;i<=n;i++){
		x=max(x,f[m][i]);
	}
	cout<<x;
}
void s678910(){
	int x=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			x=max(x,a[i]);
		}
	}
	if(m==n){
		x=a[1];
		for(int i=2;i<=n;i++){
			x=x&a[i];
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=max(x,a[i]&a[j]);
			}
		}
	}
	cout<<x;
}
void s13(){
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20)s12345();
	else if(n<=2000)s678910();
	else s13();
	return 0;
}
