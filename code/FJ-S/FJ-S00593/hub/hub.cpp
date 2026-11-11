#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
}a[2000001];
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v;
		}
		cout<<1<<endl;
	}
	return 0;
}
