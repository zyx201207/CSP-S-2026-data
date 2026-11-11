#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){//两张车票对应的座位是否在同一节车厢
        cout<<1;
    }else{
        cout<<0;
        cout<<"000"<<endl;
        return 0;
    }

    int g1=(s1[0]*10-'0')+(s1[1]-'0');//1座位号
    int g2=(s2[0]*10-'0')+(s2[1]-'0');//2座位号
    char a1=s1[2];
    char a2=s2[2];
    if(g1==g2){//两张车票对应的座位是否在同一节车厢的同一排
        cout<<1;
        if(a1<='C'&&a2<='C'||a1>='D'&&a2>='D'){//且位于过道的同一侧
            cout<<1;
        }else{
            cout<<0;
        }
        if(abs(int(a2-a1))==1&&!((a1=='D'&&a2=='C')||(a1=='C'&&a2=='D'))){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
//        cout<<g1<<" "<<g2<<endl;
        cout<<0;
        cout<<0;
        if(s1[2]==s2[2]&&abs(g1-g2)==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }

    return 0;
}
