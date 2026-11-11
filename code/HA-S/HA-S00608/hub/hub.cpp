#include<bits/stdc++.h>
using namespace std;
int t,n,k,u[10000010],v[10000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t>>n>>k;
	for(int i=0;i<n-1;i++){
		cin>>u[i]>>v[i];
	}
	cout<<(n-1)/k<<endl;
	return 0;
}
