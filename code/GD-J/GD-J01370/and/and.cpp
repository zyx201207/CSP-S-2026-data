#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
long long b[10005];
long long maxx=-19999;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				b[i]=a[i]&a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,b[i]);
	}
	cout<<maxx;
	return 0;
}
