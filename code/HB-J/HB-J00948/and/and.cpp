#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		if(m==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				maxn=max(maxn,a[i]);
			}
			cout<<maxn;
		}
		if(m==n){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				maxn&=a[i];
			}
			cout<<maxn;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
		}
	}
	return 0;
}


