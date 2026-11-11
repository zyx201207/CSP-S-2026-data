#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string cy,cr,sy,sr;
cin>>cy>>sy>>cr>>sr;
if(cy==cr){//两张车票对应的座位是否在同一节车厢
    cout<<1;
    if(sy[0]==sr[0]&&sy[1]==sr[1]){//两张车票对应的座位是否在同一节车厢的同一排
        cout<<1;
        if(sy[2]=='A'&&sr[2]=='B'||sy[2]=='A'&&sr[2]=='C'||sy[2]=='B'&&sr[2]=='C'||sy[2]=='D'&&sr[2]=='F'||sr[2]=='A'&&sy[2]=='B'||sr[2]=='A'&&sy[2]=='C'||sr[2]=='B'&&sy[2]=='C'||sr[2]=='D'&&sy[2]=='F'){
            cout<<1;//两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
            if(sy[2]=='A'&&sr[2]=='B'||sr[2]=='A'&&sy[2]=='B'||sy[2]=='C'&&sr[2]=='B'||sr[2]=='C'&&sy[2]=='B'||sr[2]=='D'&&sy[2]=='F'||sy[2]=='D'&&sr[2]=='F'){
                cout<<1;//两张车票对应的座位是否相邻
            }else cout<<0;
        }else cout<<"00";
    }else cout<<"000";
}else cout<<"0000";


return 0;
}

