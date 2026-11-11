#include<bits/stdc++.h>
using namespace std;

int a1,b1,a2,b2;
char c1,c2;
bool f[5];
bool same(char a,char b){
    if(a=='D'&&b=='F'||a=='F'&&b=='D')return 1;
    else if(a>='A'&&a<='C'&&b>='A'&&b<='C')return 1;
    return 0;
}
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if(a1!=a2)return cout << "0000",0;
    f[1]=1;
    if(b1==b2){
        f[2]=1;
        if(same(c1,c2)){
            f[3]=1;
            if(abs(c1-c2)==1||c1=='D'&&c2=='F')f[4]=1;
        }
    }
    for(int i=1;i<=4;i++){
        if(f[i])cout << 1;
        else cout << 0;
    }
    return 0;
}