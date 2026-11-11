#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],z=0,s,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=m;i++){
		for(int j=1;j<n;j++){
			if((a[j]&a[j+1])>z){
				z=a[j+1]&a[j];
				s=j;
				w=j+1;
			}
		}
		a[s]=0;
		a[w]=0;
	}
	cout<<z;
	return 0;
} 
