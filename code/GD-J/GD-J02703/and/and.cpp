#include<bits/stdc++.h>
using namespace std;
const int N=1e7+300;
int n,m,a[N],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
