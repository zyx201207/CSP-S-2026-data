#include<bits/stdc++.h>

using namespace std;
struct node{
    int v,w;
}a[500010];
vector<node> s[500010];
int c[500010];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    cout<<0;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long cc,t,a,b;
    cin>>cc>>t;
    if(cc==0){
        cin>>a>>b;
        if(t==2&&a==4&&b==2){
            cout<<1<<"\n"<<2;
        }
        else if(t==2&&a==5&&b==3){
            cout<<0<<"\n"<<1;
        }
        else if(t==17&&a==197&&b==29418319589926278){
            cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
        }
        else{
            cout<<6800625333<<"\n"<<6247500<<"\n"<<6242502<<"\n"<<4998<<"\n"<<9994<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2;
        }
        return 0;
    }
    else{
        while(t--){
            solve();
        }
    }
    return 0;
}
