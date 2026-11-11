#include<bits/stdc++.h>
using namespace std;
int cr,cx,src,sxc;
string sr,sx;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(sr[2]>='A'&&sr[2]<='C'){
        src=1;
    }
    else{
        src=2;
    }
    if(sx[2]>='A'&&sx[2]<='C'){
        sxc=1;
    }
    else{
        sxc=2;
    }
    bool tc=(cr==cx);
    bool tp=(cr==cx)&&sr.substr(0,2)==sx.substr(0,2);
    bool tpc=(cr==cx)&&sr.substr(0,2)==sx.substr(0,2)&&src==sxc;
    bool tl=(cr==cx)&&sr.substr(0,2)==sx.substr(0,2)&&(sr[2]-sx[2]==1||sx[2]-sr[2]==1)&&src==sxc;
    cout<<tc<<tp<<tpc<<tl;
    return 0;
}
