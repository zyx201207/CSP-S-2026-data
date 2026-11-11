#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		int n,k;
		cin>>n>>k;
		int a[n],b[n];
		for(int i=1;i<n;i++)cin>>a[i]>>b[i];
		cout<<n/k-1<<endl;
	}
}
