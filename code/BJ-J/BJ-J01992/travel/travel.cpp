#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    int f=0;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        f++;
        cout<<"1";
    }
    else cout<<"0";
    int c1=(c[0]-'0')*10+(c[1]-'0');
    int d1=(d[0]-'0')*10+(d[1]-'0');
    if(c1==d1&&f==1){
        f++;
        cout<<"1";
    }
    else cout<<"0";
    int c2=c[2]-'A'+1;
    int d2=d[2]-'A'+1;
    if( ( (c2<=3&&d2<=3) || (c2>=4&&d2>=4) ) && f==2){
        f++;
        cout<<"1";
    }
    else cout<<"0";
    if(f==3){
        if(abs(c2-d2)==1) cout<<"1";
        else cout<<"0";
    }
    else cout<<"0";
    cout<<endl;
    return 0;
}
