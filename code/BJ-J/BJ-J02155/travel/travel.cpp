#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    int x,y;
    bool f[4]={false,false,false,false};
    string aa,bb;
    cin>>a>>aa>>b>>bb;
    char a1=aa[2],b1=bb[2];
    x=(aa[0]-'0')*10+aa[1]-'0';
    y=(bb[0]-'0')*10+bb[1]-'0';
    if(a==b){
        f[0]=true;
        if(x==y){
            f[1]=true;
            if((a1=='B'||a1=='C'||a1=='A')&&(b1=='A'||b1=='B'||b1=='C')){
                f[2]=true;
                if(b1=='B'&&(a1=='A'||a1=='C')){
                    f[3]=true;
                }if(a1=='B'&&(b1=='C'||b1=='A')){
                    f[3]=true;
                }
            }else if((a1=='D'||a1=='F')&&(b1=='D'||b1=='F')){
                f[2]=true;
                f[3]=true;
            }
        }
    }for(int i=0;i<4;i++){
        if(f[i]==true){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}