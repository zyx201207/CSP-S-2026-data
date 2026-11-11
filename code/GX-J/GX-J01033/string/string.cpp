#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[200001],n,s=0;
    char c[200001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int km=1,m=a[1],kl=n;
    while(true){
        m-=a[kl];
        if(c[km]!=c[kl]){
            s+=a[kl];
        }
        if(kl<=s/2) cout<<s+m;
        if(m<0){
            km++;
            m+=a[km];
        }
        kl--;
    }

    return 0;
}
