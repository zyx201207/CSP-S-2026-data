#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0] && b[0]==d[0]){
            cout<<1;
            int x,y;
            if(b[2]=='F'){
                b[2]=='E';
            }else if(d[2]=='F'){
                d[2]=='E';
            }
            x=b[2]-'A'+1;
            y=d[2]-'A'+1;
            if((x<=3 && y<=3) || (x>=4 && y>=4)){
                cout<<1;
                if(abs(x-y)==1){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

