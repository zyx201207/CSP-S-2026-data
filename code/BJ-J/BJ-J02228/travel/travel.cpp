#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,k=1;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    for(int i=0;i<1;i++){
        if(s1[i]!=s2[i]){
            k=0;
            break;
        }
    }
    if(k) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'c')) cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) cout<<1;
    else cout<<0;
    return 0;
}
