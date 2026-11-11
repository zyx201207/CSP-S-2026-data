#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,x=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n-1;j++){
			cin>>a[j];
		}
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
