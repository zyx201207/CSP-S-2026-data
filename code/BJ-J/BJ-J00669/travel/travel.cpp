#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        a[i]=s1[i];
        b[i]=s2[i];
    }
    if(a==b){
        cout<<1;
    }else{
        cout<<"1000";
        return 0;
    }
    char x=s1[2];
    char y=s2[2];
    if(x-y==1&&x!='D'){
        cout<<"11";
        return 0;
    }else if(y-x==1&&y!='D'){
        cout<<"11";
        return 0;
    }
   // cout<<"00";
    if(x-y==1||y-x==1){
        cout<<"00";
        return 0;
     }
    if(x=='C'||x=='B'||x=='A'){
       if(y=='A'||y=='B'||y=='C'){
            cout<<"10";
            return 0;
        }
    }
    cout<<"00";
    return 0;
}
