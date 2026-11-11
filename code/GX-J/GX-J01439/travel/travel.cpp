
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c[4];
    string DaAn="0000";
    for(int i=0;i<4;i++){
        cin>>c[i];
    }
    if(c[0]==c[2]){
        DaAn[0]='1';
        char d=c[1][2];
        char e=c[3][2];
        string a=c[1].erase(2,1);
        string b=c[3].erase(2,1);
        if(a==b){
            DaAn[1]='1';
            if((d<='C' && e<='C') or (d>='D' && e>='D')){
                DaAn[2]='1';
                int f=d+0;
                int g=e+0;
                if(f+1==g or f-1==g){
                    DaAn[3]='1';
                }
            }
        }
    }

    cout<<DaAn;
    return 0;
}
