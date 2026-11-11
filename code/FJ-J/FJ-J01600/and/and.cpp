#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010][35],bb,s,i,j,num[40],ans[40],b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bb=n;
	for(i=1;i<=n;i++){
		cin>>s;
		b[i]=1;
		int ab=32;
		for(j=s;j>0;j=j/2){
			a[i][ab]=j%2;
			ab--;
		}
	}
	for(i=1;i<=32;i++){
		for(j=1;j<=n;j++){
			num[i]+=(a[j][i]*b[j]);
		}
		if(num[i]>=m){
			ans[i]=1;
			for(j=1;j<=n;j++){
				if(b[j]==1&&a[j][i]==0){
					b[j]=0;
				}
			}
		}
	}
	int anss=0,abb=1;
	for(i=32;i>=1;i--){
		anss+=ans[i]*abb;
		abb*=2;
	}
	cout<<anss;
	return 0;
}

