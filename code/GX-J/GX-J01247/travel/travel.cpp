#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2,pai1=0,pai2=0,zuo1,zuo2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<3;i++){
        if(i!=2){
            pai1=pai1*10+s1[i]-'0';
            pai2=pai2*10+s2[i]-'0';
        }
        else{
            zuo1=s1[i]-'A'+1,zuo2=s2[i]-'A'+1;
        }
    }

    if(c1==c2) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }

    bool TongCe=0,near=0;
    if(pai1==pai2){
        cout<<1;
        if(zuo1>=1&&zuo1<=3){
            if(zuo2>=1&&zuo2<=3) {
                TongCe=1;
                if(abs(zuo1-zuo2)==1) near=1;
            }
        }
        else if(zuo1==4||zuo1==5){
            if(zuo2==4||zuo2==5){
                TongCe=1;
                if(abs(zuo1-zuo2)==1) near=1;
            }
        }
    }
    else cout<<0;

    if(TongCe==1) cout<<1;
    else cout<<0;

    if(near==1) cout<<1;
    else cout<<0;

    return 0;
}
