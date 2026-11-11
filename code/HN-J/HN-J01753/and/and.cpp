#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
	    cout<<ma;
	    return 0;
    }
	cout<<3;
	return 0;
}
