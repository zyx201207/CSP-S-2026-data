#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int car1,car2,p1,p2;
char z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    car1=(c1[1]-'0')+(c1[0]-'0'*10);
    car2=(c2[1]-'0')+(c2[0]-'0'*10);
    p1=s1[1]-'0'+s1[0]-'0'*10;
    z1=s1[2];
    p2=s2[1]-'0'+s2[0]-'0'*10;
    z2=s2[2];
    //cout<<car1<<" "<<car2<<" "<<p1<<" "<<p2<<" "<<z1<<" "<<z2<<endl;
    if(car1!=car2){
        cout<<"0000";
        return 0;
    }else if(p1!=p2){
        cout<<"1000";
        return 0;
    }else if(!((z1=='D'&&z2=='F')||(z2=='D'&&z1=='F')||(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'))){
        cout<<"1100";
        return 0;
    }else if(!((z1=='D'&&z2=='F')||(z1=='D'&&z2=='F')||(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'&&abs((int)(z1-z2))==1))){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
