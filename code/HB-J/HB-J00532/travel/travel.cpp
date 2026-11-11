#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,s1,s2,s3,ans;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    s=' '+s;
    s1=' '+s1;
    s2=' '+s2;
    s3=' '+s3;
    for(int i=1;i<=4;i++)ans[i]=1;
    for(int i=1;i<=2;i++){
        if(s[i]!=s2[i]){
            ans[1]='0';
            //return 0;
        }
    }
    if(ans[1]=='0'){
        cout<<"0000";
        return 0;
    }
    for(int i=1;i<=2;i++){
        if(s1[i]!=s3[i]){
            ans[2]='0';
            //return 0;
        }
    }
    if(ans[2]=='0'){
        cout<<"1000";
        return 0;
    }
    if(s1[3]=='D'&&s3[3]!='F')ans[3]='0';
    if(s1[3]=='F'&&s3[3]!='D')ans[3]='0';
    if(s3[3]=='D'&&s1[3]!='F')ans[3]='0';
    if(s3[3]=='F'&&s1[3]!='D')ans[3]='0';
    if(ans[3]=='0'){
        //cout<<1;
        cout<<"1100";
        return 0;
    }
    if((s1[3]-'0')-(s3[3]-'0')>1){
        cout<<"1110";
        return 0;
    }
    //cout<<s3[3];
    cout<<"1111";
}