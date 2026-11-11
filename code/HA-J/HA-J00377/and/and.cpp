#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int MAX=0,s=0;
	for(int i=1;i<=n;i++){
		s=a[i] and a[i+1];
		MAX=max(MAX,s);
	cout<<MAX;
	}
	
	return 0;
}
