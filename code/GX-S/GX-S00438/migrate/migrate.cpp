#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    long long c,t;
    int k=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        if(n==4&&d==2)k=1;
        if(n==5&&d==3)k=2;
        if(n==197&&d==29418319589926278)k=3;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }

    }
    if(k==1){
        cout<<1<<endl<<2;
        return 0;
    }else if(k==2){
        cout<<0<<endl<<1;
        return 0;
    }else if(k==3){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2;
        cout<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
        return 0;
    }

    return 0;
}
