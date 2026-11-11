#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x,z=0;
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;j++){
		    x=a[i]&a[j];
		    z=max(x,z);
	    }
	}
	cout<<z;
	return 0;
}

