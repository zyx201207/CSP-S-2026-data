#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel1.out","w",stdout);
    cin>>a>>x>>b>>y;
    int c1,c2,c3,c4;
    if(a==b){
        c1=1;
    }else{
        c1=0;
    }
    int f1,f2;
    f1=(x[0]-'0')*10+(x[1]-'0');
    f2=(y[0]-'0')*10+(y[1]-'0');
    char p=x[2],q=y[2];
    if((f1==f2)&&c1){
        c2=1;
    }else{
        c2=0;
    }
    if((c1&&c2)&&((p=='A'&&q=='B')||(p=='A'&&q=='C')||(p=='B'&&q=='C')||(q=='A'&&p=='B')||(q=='A'&&p=='C')||(q=='B'&&p=='C')||(q=='D'&&p=='F')||(p=='D'&&q=='F'))){
        c3=1;
    }else{
        c3=0;
    }
    if((c1&&c2&&c3)&&(abs(p-q)==1)){
        c4=1;
    }else{
        c4=0;
    }
    cout<<c1<<c2<<c3<<c4;
    return 0;
}
