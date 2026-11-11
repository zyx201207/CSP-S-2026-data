#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long maxx=0,maxxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000&&m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxxx=max((a[i]&a[j]),maxxx);
			}
		}
		cout<<maxxx;
	}
	return 0;
}
