#include<bits/stdc++.h>
using namespace std;
int n,m,a[32][200005],j1=30;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		a[0][i]=l;
		while(l) a[j1][i]=l%2,l/=2,j1--;
	}
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) a[31][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[31][i]==0){
			ans=a[0][i];
			a[31][i]=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[31][i]==0) ans=ans&a[0][i];
	}
	cout<<ans;
	return 0;
}


