#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct node{
    ull shu;
    char zf;
    node(ull shu0,char zf0){
        shu=shu0;
        zf=zf0;
    }
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ull n=0,sl=0,zs=0;
    char z;
    cin>>n;
    vector<node>a;
    cin>>sl>>z;
    a.push_back(node(sl,z));
    for(ull i=1;i<n;i++){
        cin>>sl>>z;
        if(a[a.size()-1].zf==z){
            a[a.size()-1].shu+=sl;
        }
        else{
            a.push_back(node(sl,z));
        }
        zs+=sl;
    }
    ull l=0,r=a.size()-1;
    ull cnt=0,wl=0,wr=0;
    while(l<r){
        if(a[l].shu-wl<a[r].shu-wr){
            wr+=a[l].shu-wl;
            if(a[l].zf!=a[r].zf){
                cnt+=a[l].shu-wl;
            }
            wl=0,l++;
        }
        else if(a[l].shu-wl>a[r].shu-wr){
            wl+=a[r].shu-wr;
            if(a[l].zf!=a[r].zf){
                cnt+=a[r].shu-wr;
            }
            wr=0,r--;
        }
        else{
            wl=0,wr=0;
            if(a[l].zf!=a[r].zf){
                cnt+=a[l].shu-wl;
            }
            l++,r--;
        }
    }
    cout<<cnt;
    return 0;
}
