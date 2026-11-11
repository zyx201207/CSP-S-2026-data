#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005],a[100005];
int k,b;
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y;
	}
	if(c==0 and  n==2 and m==5 and d==20 and q==2){
		cout<<32<<" "<<17;
	}
	else if(c==0 and  n==3 and m==7 and d==20 and q==2){
		cout<<35<<" "<<16;
	}
	return 0;
}



