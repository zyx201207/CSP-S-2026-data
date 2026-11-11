#include<bits/stdc++.h>
using namespace std;
int a[10000000001];
int main(){
   //freopen("and.in","r",stdin);
   //freopen("and.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   }
   sort(a,a+1,a+n);
   for(int i=1;i<=n;i++){
	   if(a[i]==1){
		   a[i]==true;
    }else{
		a[i]==false;
	   cout<<m;
      return 0;
}
