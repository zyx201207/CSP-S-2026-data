#include<bits/stdc++.h>
using namespace std;
int t(string s){
    int sum=0;
    for(int i=0;i<2;i++){
        sum=sum*10+int(s[i]);
    }
    return sum;
}
int t_(char a){
    if(a=='F')return int(a-'A');
    else return int(a-'A'+1);
}
bool fb(string a,string b,string c,string d,char e,char f){
    if(a==c&&t(b)==t(d)&&((t_(e)<=3&&t_(f)<=3)||(t_(e)>3&&t_(f)>3)))return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cxhx,zwhx,cxhr,zwhr;
    cin>>cxhx>>zwhx>>cxhr>>zwhr;
    char c=zwhx[zwhx.size()-1],d=zwhr[zwhr.size()-1];
    if(cxhx==cxhr)cout<<'1';
    else cout<<'0';
    if(cxhx==cxhr&&t(zwhx)==t(zwhr))cout<<'1';
    else cout<<'0';
    if(fb(cxhx,zwhx,cxhr,zwhr,c,d))cout<<'1';
    else cout<<'0';
    if(fb(cxhx,zwhx,cxhr,zwhr,c,d)){
        if(t_(c)-1==t_(d)||t_(c)+1==t_(d))cout<<'1';
        else cout<<'0';
    }
    else cout<<'0';
    return 0;
}
