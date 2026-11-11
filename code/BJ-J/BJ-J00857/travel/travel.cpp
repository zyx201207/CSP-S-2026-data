#include<bits/stdc++.h>
using namespace std;
bool k[256];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int m=1;
    m&=(a==c);
    cout<<m;
    m&=(b.substr(0,2)==d.substr(0,2));
    cout<<m;
    k[(int)'A']=1;
    k[(int)'B']=1;
    k[(int)'C']=1;
    k[(int)'D']=0;
    k[(int)'F']=0;
    int p=b[2],q=d[2];
    m&=(k[p]==k[q]);
    cout<<m;
    if(m==0)cout<<0;
    else if(k[p]==k[q]&&k[p]==0){
        cout<<m;
    }
    else if(p=='B'||q=='B'){
        cout<<m;
    }
    else{
        cout<<0;
    }
    return 0;
}
