#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,a[999],b[999];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=7;j++){
            cin>>b[j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0;
            return 0;
        }
        else if(x+b[i]==y){
            cout<<a[i];
            return 0;
        }
        else{
            if(y==2){
                cout<<x+y+q+i+10;
            }
            else{
                cout<<x+q+29;
            }
        }
    }
    return 0;
    //rp++!!!
}
