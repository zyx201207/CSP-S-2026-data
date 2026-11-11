#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxand=0; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			if(a[j]&a[j+1]>maxand) maxand = a[j]&a[j+1];
		}
	}
	cout<<maxand;
	return 0;
}
