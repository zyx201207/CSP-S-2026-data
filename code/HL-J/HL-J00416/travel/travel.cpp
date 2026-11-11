#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in" ,"r",stdin  );
    freopen("travel.out","w",stdout );

    string ra , rb , xa , xb ;
    cin >> ra >> rb >> xa >> xb ;
    char ans[4] ;
    ans[0] = '0'+(ra==xa) ;
    ans[1] = (((ra==xa)&&((rb[0]*128+rb[1])==(xb[0]*128)+xb[1])))+'0';
    ans[2] = ((ans[1]=='1')&&(((rb[2]<'D')&&(xb[2]<'D'))||((rb[2]>'C')&&(xb[2])>'C')))+'0';
    ans[3] = '0'+((ans[1]==1)&&(rb[2]==xb[2]));
    cout << ans[0] << ans[1] << ans[2] << ans[3] ;
    return 0 ;
}
