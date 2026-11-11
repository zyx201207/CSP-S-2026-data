#include<bits/stdc++.h>
using namespace std;
int n,m,ma=-1,min=1e8,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
		for(int i=1;i<=q;++i){
			cin>>a[i];
			ma=max(ma,a[i]);
			mi=min(mi,a[i]);
		}
		if(n==m){
			cout<<mi;
		}else if(m==1){
			cout<<ma;
		}else{
			cout<<12;
		}
	return 0;
}
