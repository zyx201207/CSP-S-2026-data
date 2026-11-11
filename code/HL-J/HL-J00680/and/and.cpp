#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[618];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int y[618]={};
   sort(a,a+n,greater<int>());
   for(int i=0;i<n;i++){

    if(y[1]<=a[i]){
        y[1]=a[i];
    }
   }
   cout<<y[1];
   fclose(stdin);
   fclose(stdout);

   return 0;
}
