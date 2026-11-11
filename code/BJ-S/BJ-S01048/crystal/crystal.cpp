#include<bits/stdc++.h>
using namespace std;
int a[100];
void A(int n1){
    for(int i=0;i<n1;i++){
      for(int j=i+1;j<n1;j++){
            for(int y=1;y>=0;y++){
               for(int x=i+1;x<n1;i++){
                   int b=1;
                   if(a[i]==a[j]+y){
                      int q=0;
                      f=a[i+1];
                      a[i+1]=a[j];
                      a[j]=q;
                      coutinue;
                     }
                   }
               }
          }
     } 
     return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    A(n);
    int c=0,d=0;
    for(int i=0;i<n;i++){
    if(c>=m){
       coutinue;
    }else{
       for(int i=0;i>0;i++){
           if(a[i]==a[i+1]){
              break;
           }else{
              a[i]+=1;
              c++;
           }
       }
       d++;
       }
    }
    cout<<d;
    return 0;
}