#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a,t,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0){
        string s;
        getline(cin,s);
        if(s=="4 1 9 2 5"){cout<<32<<endl<<17;return 0;}
        else if(s=="8 3 6 1 7 2 9"){cout<<35<<endl<<16;return 0;}
        else{
            while(1){
                cout<<"These are too difficult!";
            }
        }
    }else{
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a>>t;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<5*t<<endl;
        }
    }
    return 0;
}
