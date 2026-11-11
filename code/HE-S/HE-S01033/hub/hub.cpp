#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,a[1000010],b[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>a[i]>>b[i];
		}sort(a+1,a+1+n);
		while(a[1]--){
			if(b[1]%2)b[1]=b[1]*5-1;
			else b[1]=b[1]/2+1; 
		}cout<<b[1]<<"\n";
		
	}
	return 0;
}
