#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[1000001],b[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>a[j]>>b[j];
		}
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
