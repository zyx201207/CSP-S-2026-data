#include <bits/stdc++.h>

using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    //cout << "Hello world!" << endl;
    string n,n1,m,m1;
    cin>>n>>n1>>m>>m1;
    if(n[0]==m[0]&&n[1]==m[1]){
        cout<<"1";
        if(n1[0]==m1[0]&&n1[1]==m1[1]){
            cout<<"1";
            if(n1[2]>='A'&&n1[2]<='C'&&m1[2]>='A'&&m1[2]<='C'){
                cout<<"1";
                if(n1[2]-1==m1[2]||n1[2]+1==m1[2]){
                    cout<<"1";
                }else{
                cout<<"0";
                }
            }else if((n1[2]=='D'||n1[2]=='F')&&(m1[2]=='D'||m1[2]=='F')){
            cout<<"11";//return 0;
            }else{
            cout<<"00";
            }
        }else{
        cout<<"000";
        }
    }else{
    cout<<"0000";
    }

    return 0;
}
