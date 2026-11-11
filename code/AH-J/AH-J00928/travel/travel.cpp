#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int chexiang;
    string zuowei;
};
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    node x,r;
    cin>>x.chexiang>>x.zuowei>>r.chexiang>>r.zuowei;
    if(x.chexiang==r.chexiang) {
        cout<<1;
        int xh=x.zuowei[0]*10+x.zuowei[1]*1;
        int rh=r.zuowei[0]*10+r.zuowei[1]*1;
        if(xh==rh){
            cout<<1;
            bool xl=1,rl=1;
            if(x.zuowei[2]>='A' && x.zuowei[2]<='C') xl=0;
            if(r.zuowei[2]>='A' && r.zuowei[2]<='C') rl=0;
            if(xl==rl){
                cout<<1;
                if(xl==1){
                    cout<<1;
                    return 0;
                }else{
                    if(abs(x.zuowei[2]-r.zuowei[2])==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }

    return 0;
}
