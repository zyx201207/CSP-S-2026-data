#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
long long a,s,d[1000000];
cin>>a>>s;
for(int p=0;p<a;p++){
 cin>>d[p];
}
sort(d,d+a);
for(int i=a-1;i>=a-s;i--){
    cout<<d[i]<<" ";
}
return 0;
freopen("and.out","w",stdout);
}
