#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.in","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1==c2){
        cout<<1<<endl;
    }
    else cout<<0<<endl;
    if(s1%s2==0){
        cout<<1<<endl;
    }
    else cout<<0<<endl;
    else if(s1!=s2){
        cout<<0<<endl;
    }
    else if(s1%s2!=0){}
    cout<<0<<endl;
}
return 0;
