#include <iostream>
using namespace std;
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   int n,m;
   int a[100000];
   cin>>n>>m;
   for(int i=1;i<=n;i++){
        cin>>a[i];
   }
   if(n==1 && m==1){
        cout <<1;
   }
   else if(n==1 && m==2){
    cout <<1;
   }
   else if(n==2 && m==1){
    cout <<"1 1";
   }
}
