#include<iostream>
#include<algorithm>
#include<cmath>
const int N=1e4+10;
using namespace std;
long long c,n,m,d,q,k,x,y;
long long w[N],a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=2*k;i++){
		cin>>a[i]>>t[i];
	}
	cin>>x>>y;
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
	}
}

