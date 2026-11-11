#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        int cc=(c[0]-'0')*10+(c[1]-'0');
        int dd=(d[0]-'0')*10+(d[1]-'0');
        if(cc==dd){
            cout<<1;
            cc=(c[2]-'A');
            dd=(d[2]-'A');
            if(cc>=0&&cc<=2){
                if(dd>=0&&dd<=2){
                    cout<<1;
                    if(cc-1==dd||dd-1==cc){
                        cout<<1;
                        return 0;
                    }else{
                        cout<<0;
                        return 0;
                    }
                }else{
                    cout<<"00";
                    return 0;
                }
            }else if(cc>=3&&cc<=4){
                if(dd>=3&&dd<=4){
                    cout<<"11";
                    return 0;
                }else{
                    cout<<"00";
                    return 0;
                }
            }else{
                cout<<cc;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
