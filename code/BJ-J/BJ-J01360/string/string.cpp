#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=5e5+10,Z=1e18,M=3e5+10;

int n,t,a[N],ans;
string b[N];

void qweasd(){
    cin>>n;
    vector<PII> h,t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ans+=a[i];
    }
    int x=1;
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(x<=ans/2)h.pb({x,i});
        //else if(x<=ans/2&&x+a[i]-1>=ans/2) h[i].pb(x,i);
        x+=a[i];
    }
    x=1;
    for(int i=n;i>=1;i--){
        if(x<=ans/2)t.pb({x,i});
        //else if(x<=ans/2&&x+a[i]-1>=ans/2) h[i].pb(x,i);
        x+=a[i];
    }
    /*for(int i=0;i<h.size();i++) cout<<h[i].x<<" ";
    cout<<endl;
    for(int i=0;i<t.size();i++) cout<<t[i].x<<" ";
    cout<<endl;
    */
    int tt=n,hh=1;
    int res=0;
    for(int i=0,j=0;i<h.size()&&j<t.size();){
        //cout<<i<<" "<<j<<endl;
        int x=h[i].y,y=t[j].y;
        int l1=h[i].x,r1=h[i].x+a[x]-1,l2=t[j].x,r2=t[j].x+a[y]-1;
        r2=min(r2,ans/2),r1=min(r1,ans/2);
        if(r2<l1)j++;
        else if(r2<=r1&&l2<=l1){
            if(b[x]!=b[y])res+=r2-l1+1;
            j++;
            //cout<<j<<" ";
        }
        else if(r2>r1&&l2<=l1){
            if(b[x]!=b[y])res+=r1-l1+1;
            i++;
        }
        else if(r2<=r1&&l1<=l2){
            if(b[x]!=b[y])res+=r2-l2+1;
            j++;
        }
        else if(r2>r1&&l1<=l2){
            if(b[x]!=b[y])res+=r1-l2+1;
            i++;
        }
        else if(l2>r1){
            i++;
        }
    //cout<<r2-l1<<endl;
    }
    cout<<res<<endl;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    t=1;

    while(t--){

        qweasd();

    }
    return 0;
}
