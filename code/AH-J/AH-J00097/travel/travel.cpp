#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>x>>y;
    if(a==x){
        cout<<1;
        bool flag=1;
        for(int i=0;i<b.size()-1;i++){
            if(b[i]!=y[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<1;
            if(b[b.size()-1]<='C'&&y[y.size()-1]<='C'){
                cout<<1;
                if(b[b.size()-1]+1==y[y.size()-1]||y[y.size()-1]+1==b[b.size()-1]) cout<<1;
                else cout<<0;
            }else if(b[b.size()-1]>='D'&&y[y.size()-1]>='D'){
                cout<<"11";
            }else{
                cout<<"00";
            }
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
