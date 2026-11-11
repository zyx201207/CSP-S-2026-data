#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[100005][3];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
		for(int i=1;i<=t;i++){
		cin>>n>>k;
		int p=n/(k*3);
		for(int j=1;j<n;j++){
			cin>>a[j][1]>>a[j][2];
		}
		if(p*k*3!=n){
			cout<<p+1;
		}else{
			cout<<p;
		}
	}
	return 0;
}
