/*freopen("travel.ans","r",stdout);
wochangchangzhuiyiguoqv.
shengmingshunjiandinggezainaohai,wojiangbeihoudeshijianzhedie\caijian\quanqv,rouniechengtianshangduoduobaiyun.*/
//chutirensimalechuxiaomoni
//"lvyou"keyifanyiwei"tourist"ma
#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    cin>>n>>s>>m>>ss;
    //cout<<n<<' '<<s<<' '<<m<<' '<<ss;//asdfghjkl
    if(n==m){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((s[2]<'D'&&ss[2]<'D')||(s[2]>'C'&&ss[2]>'C')){//zenmemeiyou E a!!!
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s[2]-ss[2])==1||(s[2]=='F'&&ss[2]=='D')||(ss[2]=='F'&&s[2]=='D')){//zenmemeiyou E a!!!!!!!!!!!!!!!!!!!
        cout<<1;
    }
    else{
        cout<<"0";
    }
    return 0;
}
