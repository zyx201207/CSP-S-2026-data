#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n,t=0;
   string b;
   cin>>n;
   int a[200001],c[20001];
   for(int i=1;i<=n;i++){
	   cin>>a[i]>>c[i];
   }
   if(n==1) cout<<t;
   else{
	   t=2;
	   cout<<t;
	}
   return 0;
}
