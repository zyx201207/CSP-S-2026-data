#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,yy="";
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]){
        yy+="1";
        if(b[0]==d[0] and b[1]==d[1]){
            yy+="1";
            if( (b[2]<='C' and d[2]<='C') or  (b[2]>='D' and d[2]>='D')  ){
                yy+="1";
                if(  b[2]+1==d[2] or d[2]+1==d[2]   ){
                    yy+="1";
                }else{
                    yy+="0";
                }
            }else{
                yy+="00";
            }
        }else{
            yy+="000";
        }
    }else{
        yy="0000";
    }
    cout<<yy;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
