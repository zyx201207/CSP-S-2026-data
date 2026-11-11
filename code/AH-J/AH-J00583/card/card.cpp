#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=3*1e5+10;
int n,m,a[N],b[M],c[M];
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
	   c[a[i]]=i;
   }
   for(int i=1;i<=n;i++){
	   for(int j=c[a[i]];j<=n;j++){
		   if(c[a[j]]!=j){
			   j=c[a[j]];
			   b[a[j]]++;
		   }else b[a[j]]++;
	   }
   }
   for(int i=1;i<=m;i++){
	   cout<<b[i]<<" ";
   }
   return 0;
}
