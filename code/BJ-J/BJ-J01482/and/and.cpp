#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int b,c;
   cin>>b>>c;
   for(int i=1;i<=b;i++){
        cin>>a[i];
   }
   sort(a+1,a+b+1);
   int pos;
   for(int i=b;i>=1;i--){
        if(c==0){
            break;
        }
        c--;
        pos=a[i];
   }
   cout<<pos;
    return 0;
}
