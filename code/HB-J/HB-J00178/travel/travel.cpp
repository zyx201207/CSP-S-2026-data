#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
    cin>>c>>s>>cc>>ss;
    string a;
    a+=s[0];
    a+=s[1];
    string b;
    b+=ss[0];
    b+=ss[1];
    int m=(int)s[2];
    int n=(int)ss[2];
    if(c==cc){
        cout<<1;
        if(a==b){
            cout<<1;
            if(m>=65&&m<=67&&n>=65&&n<=67){
                cout<<1;
                if(abs(m-n)==1){
                    cout<<1;
                }else cout<<0;
            }else if(m>=68&&m<=70&&n>=68&&n<=70){
                cout<<"11";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
