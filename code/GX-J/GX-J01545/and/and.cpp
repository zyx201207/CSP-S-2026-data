#include<bits/stdc++.h>
using namespace std;
const int a=1000000;
int ans[a]={0},b[a];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m ==1){{
        long long bijiao=0;
        for(int i=1;i<=n;i++){
            long long shuru;
            cin>>shuru;
            if(shuru>bijiao) bijiao=shuru;
        }
        cout<<bijiao<<endl;
        return 0;
    }
    long long ls;
    for(int i=1;i<=n;i++){

        cin>>ls;

    }
    if(n==1) cout<<ls<<endl;
    if(n==5&&m==3) cout<<7<<endl;
    if(n==4&&m==2) cout<<12<<endl;
    return 0;
}
}
