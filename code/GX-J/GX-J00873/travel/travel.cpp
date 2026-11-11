#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4,p1,p2;
    char z1,z2;
    cin>>c1>>c2>>c3>>c4;
    for (int i=0;i<c2.size();i++){
            if(i==0||i==1){
                p1+=c2[i];
            }
            if(i==2){
                z1=c2[i];
            }
    }
        for (int i=0;i<c4.size();i++){
            if(i==0||i==1){
                p2+=c4[i];
            }
            if(i==2){
                z2=c4[i];
            }
    }
    bool l=false;
    cout<<(c1==c3);
    if(c1==c3){
        cout<<(p1==p2);
        if(p1==p2){
            if(z1>='A'&&z1<='C'){
                l=(z2>='A'&&z2<='C');
            }else{
                l=(z2>='D'&&z2<='F');
            }
            if(l){
                cout<<"1"<<(abs(z1-z2)==1);
            }else{cout<<"00";
        }

        }
        else{cout<<"00";}
        }else{cout<<"000";}
    return 0;
}
