#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
//    ios::sync_whitout_stdio(false);
   // cin.tie(0);
    int cc,cs;
    string szc,szs;
    cin>>cc>>szc>>cs>>szs;
    int zc=szc[0]*10+szc[1];
    char c=char(szc[2]);
    int zs=szs[0]*10+szs[1];
    char s=char(szs[2]);
    if(cc==cs){
        cout<<1;
    }else{
        cout<<0;
    }

     bool f=0;
    if(zc==zs&&cc==cs){
        cout<<1;
        f=1;
    }
    else {
        cout<<0;
    }

    if(f==1){

        if(s=='D'&&c=='F'||c=='D'&&s=='F'){
            cout<<11;
        }else{
            if(s=='A'&&c=='B'||s=='A'&&c=='C'||s=='C'&&c=='B'||
            c=='A'&&s=='B'||c=='A'&&s=='C'||c=='C'&&s=='B'){
                cout<<1;
            }else {
                cout<<0;
            }
        }
    }else{
        cout<<"0";
    }
    if(f==1){
        if(s=='A'&&c=='B'||s=='B'&&c=='C'||
        s=='B'&&c=='A'||s=='C'&&c=='B'
        ||s=='D'&&c=='F'||c=='D'&&s=='F'){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<"0";
   }








    return 0;
}
