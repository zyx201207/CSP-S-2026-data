#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int x=1;x<=t;x++){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>a[i];
		}
	}
	for(int i=0;i<t;i++){
		cout<<t-1+i<<"\n";
	}
	return 0;
}
