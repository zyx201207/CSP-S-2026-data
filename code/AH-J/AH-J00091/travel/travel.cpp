#include<iostream>
#include<string>
using namespace std;
string s1,s2,c1,c2;
bool flag1(string a,string b){
    for(int i=0;i<2;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
bool flag2(string a,string b){
    for(int i=0;i<2;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
bool flag4(string a,string b){
    if(a[2]>='D'&&b[2]>='D') return 1;
    else{
        if(a[2]-b[2]==1||b[2]-a[2]==1) return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(flag1(c1,c2)){
        cout<<1;
        if(flag2(s1,s2)){
            cout<<1;
            if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')){
                cout<<1;
                if(flag4(s1,s2)) cout<<1;
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}

