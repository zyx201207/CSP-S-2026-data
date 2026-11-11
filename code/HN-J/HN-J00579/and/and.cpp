#include<bits/stdc++.h>
using namespace std;
int n,m,v[200005],f[200005],w[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i],f[1]=max(f[1],v[i]);	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=2;j--){
			if(f[j]>f[j-1]&v[i]){
				f[j]=f[j];
			}else{
				f[j]=f[j-1]&v[i];
			}
		}
	}
cout<<f[m];
	return 0;
} 

