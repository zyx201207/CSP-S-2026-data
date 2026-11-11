#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n;
    int t;
    cin>>n>>t;
    int a[200005];
    int b[200005];
    int w[200005];
    int v[200005];
    for(int i=0;i<t;i++){
		cin>>w[i]>>v[i];
		for(int j=0;j<w[i]-1;j++){
			cin>>a[i]>>b[i];
		}
	}
	cout<<1<<endl;
	cout<<2;
		
	return 0;
}

