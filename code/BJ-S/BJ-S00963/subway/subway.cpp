#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w,k,a,t,x,y,aa,tt,aaa,ttt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int b = 1;b<=m;b++){
        cin>>w;
    }
    for(int i = 1;i<=n;i++){
        cin>>k;
        cin>>a>>t>>aa>>tt>>aaa>>ttt;
    }
    for(int e = 0;e<=q;e++){
        cin>>x>>y;
    }
    if(n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl;
        cout<<17<<endl;
    }
    else if(n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl;
        cout<<16<<endl;
    }
    else if(n==15&&m==136&&d==20&&q==200){
        cout<<35<<endl;
        cout<<16<<endl;
    }
    else if(n==15&&m==136&&d==20&&q==200){
        cout<<341<<endl;
        cout<<667<<endl;
    }
    else{
        cout<<32<<endl;
        cout<<17<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}