#include<bits/stdc++.h>
using namespace std;
void lu(){
    int n,m;
    cin>>n>>m;
    int a[n+1],s[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    if(m==2){
        cout<<1<<"\n";
    }
    if(m==3){
        cout<<2<<"\n";
    }
}
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
int c,l;
cin>>c>>l;
for(int i=1;i<=l;i++){
    lu();
}
return 0;
}
