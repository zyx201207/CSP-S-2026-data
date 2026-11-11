#include<bits/stdc++.h>
using namespace std;
char x[100000005],c[100000005];
int a[2000005];
int n,m,y,ans,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<a[i];j++){
			x[m+j]=c[i];
			z++;
		}
		m+=a[i];
	}
	m=z/2;
	y=z-m;
	if(m==y){
		m--;
	}
	y=z;
	for(int i=y;i>m;i--){
		if(x[i-1]!=x[y-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
