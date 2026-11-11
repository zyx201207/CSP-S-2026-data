#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    int a1,a2,b1,b2;
    if(c1[0]=='0') a1=c1[1]-'0';
    else a1=(c1[0]-'0')*10+(c1[1]-'0');
    if(c2[0]=='0') a2=c2[1]-'0';
    else a2=(c2[0]-'0')*10+(c2[1]-'0');
    if(a1==a2){
        ans=ans+'1';
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]=='0') b1=s1[1]-'0';
    else b1=(s1[0]-'0')*10+(s1[1]-'0');
    if(s2[0]=='0') b2=s2[1]-'0';
    else b2=(s2[0]-'0')*10+(s2[1]-'0');
    if(b1==b2){
        ans=ans+'1';
    }
    else{
        cout<<"1000";
        return 0;
    }
    int c=s1[2]-'A'+1,cc=s2[2]-'A'+1;
    if((c<=3&&cc<=3)||(c>=4&&cc>=4)){
        ans=ans+'1';
    }
    else{
        cout<<"1100";
        return 0;
    }
    if(abs(c-cc)==1&&c+cc!=7){
        ans=ans+'1';
    }
    else{
        cout<<"1110";
        return 0;
    }
    cout<<ans;
    return 0;
}
