#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			a[0]=a[i];
		}
	}
	cout<<a[0];
	return 0;
}
