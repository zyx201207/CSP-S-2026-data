#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int am=-1;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=a[i]<<a[j];
			am=max(x,am);
		}
	}
	cout<<am;
}
