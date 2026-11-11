#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
string a,as,b,bs;
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>as>>b>>bs;
    if(a==b){
        cout<<"1";
        if(as.substr(0,2)==bs.substr(0,2)){
            cout<<"1";
            if((as[2]-'A'+1<4 && bs[2]-'A'+1<4) || (as[2]-'A'+1>3 && bs[2]-'A'+1>3)){
                cout<<"1";
                if((abs(as[2]-bs[2])==1) || (as[2]=='D'&&bs[2] == 'F')){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{cout<<"0000";}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
