#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int h=0;int ans=0;
	for(int k=30;k>=0;k--){
		h=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<k)){
				h++;
				b[h]=a[i];
			}
		}
		if(h>=m){
			n=h;
			for(int i=1;i<=n;++i){
				a[i]=b[i];
			}ans+=(1<<k);
		}
	}cout<<ans;
	return 0;
}
