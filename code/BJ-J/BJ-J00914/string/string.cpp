#include <iostream>
#include <cstring>
using namesapce std;
freopen("travel.in","r",std.in)
freopen("travel.out","w",std.out)
int main(){
     long long n,c;
     cin >> n;
     char a[250000];
     int b[250000];
     for(int i=1;i<=n*2;i++){
        if(i%2==0)
        cin >> a[i];
        else
        cin >> b[i];
     }
     if(n%2==0){
    for(int i=1;i<=(n/2)*2;i++){
         for(int j=n;j>=(n/2)*2;j--){
               if(a[i]!=a[j]){
                   a[j]=a[i];
                   c=c+b[i]/2.0;
               }
         }
    } 
    }
    else{
       for(int i=1;i<=(n/2)*2;i++){
         for(int j=n;j>=(n/2)*2;j--){
         while(i+1==j){
            if(b[i/2]!=b[i/2+1]){
                 c=c-b[i];
            }
            }
         if(a[i]!=a[j]){
                   a[j]=a[i];
                   c=c+b[i]/2.0;
               }
    
         } 
    }}
    cout << c << endl;
    return 0;
}