#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    string x="";
    string y="";
    x=x+s1[0]+s1[1];
    y=y+s2[0]+s2[1];
    char d1,d2;
    d1=s1[2];
    d2=s2[2];
    if(c1==c2){
        cout<<1;
        //cout<<x<<' '<<y<<endl;
        //cout<<d1<<' '<<d2<<endl;
        if(x==y){
            cout<<1;
            if(!((d1=='D'||d1=='F')^(d2=='D'||d2=='F'))){
                cout<<1;
                if(d1<d2) swap(d1,d2);
                if(d1-d2==1 || ((d1=='D'||d1=='F')&&(d2=='D'||d2=='F'))) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
