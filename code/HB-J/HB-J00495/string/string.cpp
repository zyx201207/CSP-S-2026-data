
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   char m[1000];
   char m1[1000];
   int f=0;
   int n;
   cin>>n;
   int y=0;
   for(int i=0;i<n;i++){
    int x=0;
    char a;
    cin>>x;
    cin>>a;
    for(int j=0;j<x;j++){
        m[y]=a;
        y++;
    }
   }
   int p1=0;
   for(int i=y;i>=0;i--){
        m1[i]=m[p1];
        p1++;
   }
   for(int i=y;i>=0;i--){
        if(m1[i]!=m[i]) f++;
   }
   cout<<f-2;
    return 0;
}
