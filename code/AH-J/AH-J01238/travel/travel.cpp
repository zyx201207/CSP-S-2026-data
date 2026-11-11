#include<bits/stdc++.h>
using namespace std;
#define int long long
string cr,sr,cx,sx;
int r,x;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    r=(sr[0]-'0')*10+sr[1];
    x=(sx[0]-'0')*10+sx[1];
    if(cr!=cx)cout<<"0000"<<endl;
    else if(r!=x)cout<<"1000"<<endl;
    else if(!(((sr[2]<='C')&&(sx[2]<='C'))||((sr[2]>='D')&&(sx[2]>='D'))))cout<<"1100"<<endl;
    else if(abs(sr[2]-sx[2])>1)cout<<"1110"<<endl;
    else cout<<"1111"<<endl;
    return 0;
}
