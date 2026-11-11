#include<bits/stdc++.h>
using namespace std;
int n,t,c,k;
struct sub{
	int u,v;
}a[100000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int a1=1;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<=n;i++) {
		    cin>>a[i].u>>a[i].v;
		}
    	cout<<a1;
    	a1++;
	}
    return 0;
}
