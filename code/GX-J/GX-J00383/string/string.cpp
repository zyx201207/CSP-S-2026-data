#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("string.in";"r";stdin);
    freopen("string.out";"w";stdout);
    cin>>n;
    int a[n];
    char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int m=0;
   for(int i=0;i<n-1;i++){
    if(c[i]==c[i+1]){
        m++;
    }
   }
if(m==n-1){
    cout<<0;
    return 0;
}
cout<<a[0];
return 0;
}
