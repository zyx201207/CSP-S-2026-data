#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2;
    int c1,c2,p1,p2,l1,l2;
    cin>>c1>>s1>>c2>>s2;
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    l1=s1[2]-'A'+1;
    l2=s2[2]-'A'+1;
    if(l1==6)l1--;
    if(l2==6)l2--;
    if(c1==c2){
        cout<<1;
        if(p1==p2){
            cout<<1;
            if((l1<=3&&l2<=3)||(l1>=4&&l2>=4)){
               cout<<1;
               if(abs(l1-l2)==1)cout<<1;
               else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
//8:42~8:57 0->100
