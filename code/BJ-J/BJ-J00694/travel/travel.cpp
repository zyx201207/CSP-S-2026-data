#include<bits/stdc++.h>
using namespace std;
#define int long long
bool issameside(string x,string y){
    if(x[2]<='C'&&y[2]<='C')return true;
    if(x[2]>='D'&&y[2]>='D')return true;
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        if(c2[0]==s2[0]&&c2[1]==s2[1]){
            cout<<1;
            if(issameside(c2,s2)){
                cout<<1;
                if(abs(c2[2]-s2[2])==1){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }
    return 0;
}
