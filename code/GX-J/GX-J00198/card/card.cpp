#include<bits/stdc++.h>
using namespace std;
int a[1000005];

int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m,cnt=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(m==1){
    for(int i=1;i<=n;i++) cnt++;
    cout<<cnt;
}
if(m==2){
    cout<<n<<" "<<m;
}
return 0;
}


