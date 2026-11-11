#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,smap[7][19];
int x,xx,y,yy;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=18;j++){
            if(j>=10){
                smap[i][j]+="1";
                smap[i][j]+=(char)((j%10)+48);
            }
            else {
                smap[i][j]+="0";
                smap[i][j]+=(char)(j+48);
            }
            if(i==1) smap[i][j]+="F";
            else if(i==2) smap[i][j]+="D";
            else if(i==3) smap[i][j]+="C";
            else if(i==4) smap[i][j]+="B";
            else if(i==5) smap[i][j]+="A";
            if(smap[i][j]==s1){
                x=j;
                y=i;
            }
            if(smap[i][j]==s2){
                xx=j;
                yy=i;
            }
        }
    }
    if(c1==c2) cout<<"1";
    else cout<<"0";
    if(c1==c2&&x==xx) cout<<"1";
    else cout<<"0";
    if(c1==c2&&x==xx&&((y<=2&&yy<=2)||(y>=3&&yy>=3))) cout<<"1";
    else cout<<"0";
    if(c1==c2&&((y<=2&&yy<=2&&(max(y,yy)-min(y,yy)<=1)||((y>=3&&yy>=3)&&(max(y,yy)-min(y,yy)<=1))&&(x==xx)))) cout<<"1";
    else if(c1==c2&&y==yy&&(max(x,xx)-min(x,xx)==1)) cout<<"1";
    else cout<<"0";
    return 0;
}
