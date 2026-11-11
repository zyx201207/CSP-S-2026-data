#include <bits/stdc++.h>
using namespace std;
int t,c;
struct Node{
	int u,v;
}a[5000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.ans","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		cout<<(n&k)<<endl;
	}
	return 0; 
}
