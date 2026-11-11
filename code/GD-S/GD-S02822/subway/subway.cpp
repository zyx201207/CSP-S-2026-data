#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10000005],k[10000005],a[10000005],t[100000005],x,y;
long long find(int x,int y){
	long long ma;
	ma+=w[x]+t[x];
	for(long long i=x+1;i<=abs(y-x)-1;i++){
		ma+=t[i]+t[i];
	}
	ma+=w[y];
	return ma;
}
int main(){
	long long mm=0;
   cin>>c>>n>>m>>d>>q;
   for(long long i=1;i<=m;i++){
   	    cin>>w[i];
   }
   for(long long i=1;i<=n;i++){
   	    cin>>k[i];
   	    for(long long j=1;j<=k[i];j++){
   	        cin>>a[i];
   	        cin>>t[i];
        }
   }
   for(long long i=1;i<=n;i++){
   	    cin>>x>>y;
   	    cout<<find(x,y)<<endl;
   }
	return 0;
}
