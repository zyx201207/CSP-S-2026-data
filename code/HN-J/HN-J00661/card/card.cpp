#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],maxx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(a[i]!=a[i+1]){
			b[i]=1;
		}else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			cout<<c[i]<<" ";
		}
	}
	return 0;
} 
