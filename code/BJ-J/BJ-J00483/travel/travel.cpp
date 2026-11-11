#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    // freopen("travel.out","r",stdin);
    // freopen("travel.in","w",stdout);
    //freopen("travel.in","r",stdout);
    //freopen("travel.out","w",stdin);
    // 被骗了？ 
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s1>>s3>>s2>>s4;
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"0000\n";
        return 0;
    }
    if(s3[0]!=s4[0]||s3[1]!=s4[1]){
        cout<<"1000\n";
        return 0;
    }
    if((s3[2]>'C')^(s4[2]>'C')){
        cout<<"1100\n";
        return 0;
    }
    cout<<111<<(abs(s3[2]-s4[2])==1&&max(s3[2],s4[2])!='D')<<'\n';
    return 0;
}