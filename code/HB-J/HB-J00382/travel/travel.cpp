#include<bits/stdc++.h>
using namespace std;
int col[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    col[1]=1;
    col[2]=1;
    col[3]=1;
    col[4]=0;
    col[6]=0;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<"1";
            int col1=b[2]-'A'+1,col2=d[2]-'A'+1;
            if(col[col1]==col[col2]){
                cout<<"1";
                if(abs(col1-col2)==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
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
