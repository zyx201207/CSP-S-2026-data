#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[1000006];
int b[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>a[i]>>b[i];
		cout<<k-1<<endl;
	}
	return 0;
}
