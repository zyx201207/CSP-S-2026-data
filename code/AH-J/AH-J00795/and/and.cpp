#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000+10],maxn;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(n<=2000000&&m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=maxn&a[i];
		}
	}
	
	
	return 0;
}
