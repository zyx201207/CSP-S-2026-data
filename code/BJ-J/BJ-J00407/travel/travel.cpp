#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r_1,r_2,x_1,x_2;
    cin>>r_1>>r_2>>x_1>>x_2;
    if(r_1[0]!=x_1[0]||r_1[1]!=x_1[1]) cout<<"0000";
    else if(r_2[0]!=x_2[0]||r_2[1]!=x_2[1]) cout<<"1000";
    else if(!(('A'<=r_2[2]&&r_2[2]<='C'&&'A'<=x_2[2]&&x_2[2]<='C')||('D'<=r_2[2]&&r_2[2]<='F'&&'D'<=x_2[2]&&x_2[2]<='F'))) cout<<1100;
    else if((r_2[2]=='D'||x_2[2]=='D')||abs(x_2[2]-r_2[2])==1) cout<<1111;
    else cout<<1110;
    return 0;
}
