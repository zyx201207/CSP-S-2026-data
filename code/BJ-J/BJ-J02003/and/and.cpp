#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],cnt[35];
short hidx;
struct node{
    short t[35];
    short idx;
    int vis;
}b[N];
int cmp(node X,node Y){
    return X.idx>Y.idx;
}
short ans[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll x=a[i];
        while(x>0){
            b[i].idx++;
            b[i].t[b[i].idx]+=(x%2);
            x/=2;
        }
    }

    //cout<<0<<endl;
    sort(b+1,b+n+1,cmp);
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=b[i].idx;j++){
    //        cout<<b[i].t[j];
    //    }
    //    cout<<endl;
    //}
    //cout<<1<<endl;
    for(int i=1;i<=n;i++){
        hidx=max(hidx,b[i].idx);
        for(int j=1;j<=b[i].idx;j++){
            cnt[j]+=b[i].t[j];
        }
    }
    //cout<<2<<endl;
    //for(int i=1;i<=hidx;i++){
    //    cout<<cnt[i]<<" ";
    //}

    while(1){
        /*
        cout<<"h:";
        for(int i=1;i<=hidx;i++){
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
        */
        ll lmt=0;
        for(int i=hidx;i>=1;i--){
            if(m<=cnt[i]){
                lmt=i;
                cnt[lmt]=0;
                break;
            }
            cnt[i]=0;
        }
        //cout<<"lmt:"<<lmt<<endl;
        if(lmt==0){
            break;
        }
        ans[lmt]=1;
        if(lmt==1){
            break;
        }
        for(int i=1;i<=n;i++){
            if(b[i].idx>=lmt) b[i].idx=lmt-1;
            if(b[i].t[lmt]==0&&b[i].vis==0){
                //cout<<"die:"<<i<<endl;
                for(int j=1;j<=b[i].idx;j++){
                    cnt[j]-=b[i].t[j];
                }
                b[i].vis=1;
            }
        }
    /*
        cout<<"t:";
        for(int i=1;i<=hidx;i++){
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
        */
    }
    ll fnl=0,tmp=1;
    for(ll i=1;i<=hidx;i++){
        fnl+=tmp*ans[i];
        tmp*=2;
    }
    cout<<fnl;
    return 0;
}
