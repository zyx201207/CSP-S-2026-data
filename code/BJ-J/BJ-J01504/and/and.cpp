#include<bits/stdc++.h>
using namespace std;

int main{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>n>>m;
for(int i=1,i<=n,i++){
    cin>>a[i];
}
if(m==n){
    int temp=a[0]&a[1];
    for(int i=3,i<=n,i++){
        temp=temp*a[i];
    }
    cout<<temp-1;
}

return 0;
}
