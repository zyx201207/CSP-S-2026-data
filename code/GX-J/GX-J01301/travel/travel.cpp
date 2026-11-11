#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int rx,xx,rz,xz,rl,xl;
    string sr,sx;
    char rh,xh;
    bool a[4]={false,false,false,false};
    cin>>rx;
    cin>>sr;
    cin>>xx;
    cin>>sx;

    rz=10*(sr[0]-48)+(sr[1]-48);
    xz=10*(sx[0]-48)+(sx[1]-48);
    rh=sr[2];
    xh=sx[2];
    rl=rh;
    xl=xh;
    if(rx==xx){
        a[0]=true;
        if(rz==xz){
            a[1]=true;
            if(!(rh=='C'&&xh=='D')&&!(rh=='D'&&xh=='C')){
                if(abs(rl-xl)<=2){
                    a[2]=true;
                    if((rh=='D'&&xh=='F')||(rh=='F'&&xh=='D')){
                        a[3]=true;
                    }
                    else if(abs(rl-xl)==1) a[3]=true;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        if(a[i]) cout<<1;
        else cout<<0;
    }
    return 0;
}
//-48
