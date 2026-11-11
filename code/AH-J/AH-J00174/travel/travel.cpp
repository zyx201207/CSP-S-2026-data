#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>a>>y>>b;
    if(x==y){
        cout<<1;
        string u=a,v=b;
        u.erase(u.size()-1,1);
        v.erase(v.size()-1,1);
        if(u==v){
            cout<<1;
            char p=a[a.size()-1],q=b[b.size()-1];
            if(p<='C'){
                if(q<='C'){
                    cout<<1;
                    if((int)abs(p-q)==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }else{
                if(q>'C'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
