#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxx;
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b=a[i];
		for(int j=i;j<=n;j++){
        for(int k=1;k<m;k++){
	        b&=a[j+k];}
		maxx=max(maxx,b);}
		}
	cout<<maxx;
	return 0;
}
