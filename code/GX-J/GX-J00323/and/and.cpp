#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m=0,i=1,j;
cin>>n;
for(int a=1;a<=n;a++){
   cin>>j;
    if(i and j>=m)
        m=i and j;
}
cout<<m;

return  0;
}
