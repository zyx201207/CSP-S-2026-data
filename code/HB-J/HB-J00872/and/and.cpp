#include<iostream>
using namespace std;
int a[1000000];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++){
   cin>>a[i];
   int u=i;
   while(a[u]>a[u-1]){
	   int c=a[u-1];
	   a[u-1]=a[u];
	   a[u]=c;
	   u--;
   }
   }
   for(int i=m-2;i>=0;i++){
	   a[i]&=a[i+1];
   }
  cout<<a[0]<<endl;
	return 0;
}
