#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool a[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(a,0,sizeof(a));
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0] = 1;
        ll k1=0,k2=0;
        for(ll i=0;i<2;i++){
            char o1=s1[i],o2=s2[i];
            ll x1=o1-'0',x2=o2-'0';
            k1=k1*10+x1,k2=k2*10+x2;
        }
        if(k1==k2){
            a[1] = 1;
            char o1=s1[2],o2=s2[2];
            if(((o1=='A'||o1=='B'||o1=='C')&&(o2=='A'||o2=='B'||o2=='C')) || ((o1=='D'||o1=='E')&&(o2=='D'||o2=='E'))){
                a[2] = 1;
                if(abs(int(o1-o2))<=1){
                    a[3] = 1;
                }
            }
        }
    }
    for(ll i=0;i<4;i++){
        cout<<a[i];
    }

    return 0;
}
