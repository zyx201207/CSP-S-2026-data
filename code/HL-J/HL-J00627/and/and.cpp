#include<bits/stdc++.h>
using namespace std;
int a[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ax=-0x3f3f3f3f;
	cin>>n>>m;
	if(m==1){
		for(int i=0;i<=n;i++){
			cin>>a[i];
		    ax=max(ax,a[i]);
		}
	    cout<<ax;
	}

	return 0;
}
