#include<bits/stdc++.h>
using namespace std;
struct node{
	int p,q;
}a[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,maxn,c[1000001];
	cin>>c>>t;
	for(int x=1;x<=t;x++){
		int b[1000001];
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			c[i]=i;
		}
		for(int i=1;i<=n-1;i++){
			cin>>a[i].p>>a[i].q;
		}
		for(int i=1;i<=n-1;i++){
			b[a[i].p]++,b[a[i].q]++;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=)
		}
		
	}
	return 0;
}
