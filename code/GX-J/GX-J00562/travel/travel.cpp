#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long a,ch;
    char v,n;
    string c,ah;
    cin>>a>>c>>v>>ch>>ah>>n;
    if(a==ch){
        cout<<"1";
        if(v/10== n/0){
            cout<<"1";
            if(v<='C' && n<='C' || v>'C' && n>'C'){
                cout<<"1";
                if(abs(int(v)-int(n))){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
