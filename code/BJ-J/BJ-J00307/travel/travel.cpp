#include<bits/stdc++.h>
using namespace std;
string traina,trainb,seata,seatb;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>traina>>seata>>trainb>>seatb;
    cout<<(traina==trainb?"1":"0");
    cout<<((traina==trainb)&&(seata[0]==seatb[0])&&(seata[1]==seatb[1])?"1":"0");
    cout<<((traina==trainb)&&((seata[0]==seatb[0])&&
    (seata[1]==seatb[1]))&&((seata[2]<='C'&&seatb[2]<='C')||(seata[2]>='D'&&seatb[2]>='D'))?"1":"0");
    cout<<((traina==trainb)&&((seata[0]==seatb[0])&&(seata[1]==seatb[1]))
    &&(((seata[2]<='C'&&seatb[2]<='C')&&abs(seata[2]-seatb[2])<=1)||((seata[2]>='D'&&seatb[2]>='D')&&
    abs(seata[2]-seatb[2])<=2))?"1":"0");
    return 0;
}
