#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d,x,st,s2;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(i==1)st=x;
            if(i==2)s2=x;
        }cout<<(d%(s2-st)==0&&(d/(s2-st)>=2)?max(n-(d*2/(s2-st))+1,0LL):0)<<'\n';
    }
}
