#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=n;k>=1;k--){
			b[i]+=a[k]%2;
			a[k]/=2;
			b[i]*=10;
		} 
		b[i]/=10;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++){
			a[i]=b[i]&b[j];
			ans=a[i];
			if(a[i]>ans){
				ans=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}

