#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int n,s[2000000005],a[2000000005],sum=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>s[i];
}
for(int i=1;i<=n;i++){
    if(a[i]==a[n-i]){

    }
    else{
        sum++;
    }
}
cout<<sum;
return 0;
}
