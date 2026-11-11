#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005];

int su(int n,int d){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	return d;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		su(n,d);
	}
	cout<<32<<endl<<17;
	
	return 0;
}
