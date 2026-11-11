#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(s2[0]!=s4[0]||s2[1]!=s4[1]){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    if(s2[2]<=67&&s4[2]>67||s2[2]>67&&s4[2]<=67){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(s2[2]-s4[2]==1||s2[2]-s4[2]==-1){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}
