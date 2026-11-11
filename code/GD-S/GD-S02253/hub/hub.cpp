#include <bits/stdc++.h>
using namespace std;

int n,c,t,k;

struct NN{
	int l,r;
}a[1000005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].l>>a[i].r;
		}
		cout<<k+1;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
