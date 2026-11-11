#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c1,x1,c2,x2;
    char s1,s2;
    cin>>c1>>x1>>s1>>c2>>x2>>s2;
//    cout<<c1<<' '<<x1<<' '<<s1<<' '<<c2<<' '<<x2<<' '<<s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(x1==x2&&c1==c2){
        cout<<1;
        if((s1=='F'&&s2=='D')
           ||(s1=='d'&&s2=='F')) cout<<1;
        else if((s1=='A'||s1=='B'||s1=='C')
                &&(s2=='A'||s2=='B'||s2=='C')) cout<<1;
        else cout<<0;
    }
    else cout<<"00";

    if(c1==c2&&x1==x2
       &&((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')
          ||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')
          ||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))) cout<<1;
            else cout<<0;
    return 0;
}
