#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	
	cout<<a[n/2];
	return 0;
}
