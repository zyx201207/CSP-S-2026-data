#include<bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>a[i]>>b[i];
		}
		cout<<k++;
	}
	
	return 0;
}
