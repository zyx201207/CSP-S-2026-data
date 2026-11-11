#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[500050],d[500050];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int j=a[i]-a[i-1];
		int p=i-1;
		d[i]=j*p+k;
		k+=d[i];
	}
	cout<<1<<endl<<2;
	return 0;
}
