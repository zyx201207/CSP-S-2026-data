#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=2e5+10,Z=1e18,M=3e5+10;

int n,t,a,ans,m;
bool b[N][40];
void asd(int x,int k){
    //cout<<x<<" ";
    int idx=0;
    while(x){
        b[k][idx++]=x&1;
        x=x>>1;
    }

}
/*
bool qwe(int x){
    bool a[45],f[N];
    for(int i=0;i<=35;i++){
        a[i]=0;
    }
    for(int i=1;i<=n;i++)f[i]=1;
    int idx=0;
    while(x){
        a[idx]=x&1;
        x=x>>1;
    }

    for(int j=0;j<=31;j++){
        if(a[j]){
            for(int i=1;i<=n;i++){
                 if(b[i][j]==0) f[i]=0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f[i]) ans++;
    }
    return ans>=m;
}
*/
void qweasd(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        asd(a,i);
    }
    /*cout<<1<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=31;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }*/



    bool f[N],ans[45];
    int res=n;
    for(int i=0;i<=35;i++){
        ans[i]=0;
    }
    for(int i=1;i<=n;i++)f[i]=1;
    for(int j=31;j>=0;j--){
        int l=res;
        for(int i=1;i<=n;i++){
            if(b[i][j]==0&&f[i]) res--;
        }
        //cout<<res<<endl;
        if(res>=m){
            ans[j]=1;
            for(int i=1;i<=n;i++){
                if(b[i][j]==0&&f[i]) f[i]=0;
            }
        }
        else{
            res=l;
        }

    }
    int z=0;
    for(int i=31;i>=0;i--){
        //cout<<ans[i];
        z*=2;
        z+=ans[i];
    }
    //cout<<endl;
    cout<<z<<endl;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    t=1;

    while(t--){

        qweasd();

    }
    return 0;
}
