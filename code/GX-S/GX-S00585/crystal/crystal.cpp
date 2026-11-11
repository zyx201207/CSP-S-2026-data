#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,m;
ll a[500005];
ll cou,mxcnt,cnt;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<a[i]<<" \n"[i==n];
    }
    sort(a+1,a+n+1);
    if(m==0){
        ll macnt=0,cnt1=1;
        bool p=0;
        for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            p=1;
            cnt1++;
        }
        else cnt1=1;
        macnt=max(macnt,cnt1);
    }
    if(p==1)cout<<macnt<<endl;
    else cout<<1<<endl;
    return 0;
    }

    cou=a[2]-a[1],mxcnt=0,cnt=2;//cou<=m
    ll l=1,r=2;
    //int id=1,jid=0;
    while(r<n){
        ll rcha=(a[r+1]-a[r])*(r-l+1),lcha=a[r]-a[l];
        if(cou<=m){
            if(l==r){
                r++;
                if(cou+rcha<=m)cou+=rcha;
                //cnt++;
            }
            else if(cou+rcha<=m){
                r++;
                if(cou+rcha<=m)cou+=rcha;
            }
            else{
                l++;
                cou-=lcha;
            }
        }
        else{
                if(l+1==r)
                {
                    r++;
                    if(cou+rcha<=m)cou+=rcha;
                }
                else{
                    l++;
                    cou-=lcha;
                }
            }
            if(cou<=m) {cnt=r-l+1;mxcnt=max(mxcnt,cnt);}
        }
    if(mxcnt>1)cout<<mxcnt<<endl;
    else cout<<1<<endl;


return 0;
}
