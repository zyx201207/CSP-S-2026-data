#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

int n,m;

int x[200005];

bool a[200005][35];

void csh(int q){
    for(int i=1;i<=30;i++){
        a[q][i]=x[q]%2;
        x[q]/=2;
    }
    return;
}

bool cmp(int a,int b){
    return a>b;
}

ll mi[35];

bool v[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }/*
    if(m==1){
        cout<<mxxi;
        return 0;
    }
    if(m==2){
        int mxxx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mxxx=max(mxxx,x[i]&x[j]);
            }
        }
        cout<<mxxx;
        return 0;
    }
    if(m==n){
        int asss=x[1];
        for(int i=2;i<=n;i++){
            asss&=x[i];
        }
        cout<<asss;
        return 0;
    }*/
    for(int i=1;i<=n;i++){
        csh(i);
        /*for(int j=30;j>=1;j--){
            cout<<a[i][j];
        }
        cout<<endl;*/
    }
    mi[0]=1;
    for(int i=1;i<=30;i++) mi[i]=mi[i-1]*2;
    int asa=0;
    memset(v,1,sizeof(v));
    for(int i=30;i>=1;i--){
        int ct=0;
        for(int j=1;j<=n;j++){
                //cout<<i<<' '<<j<<endl;
            if(a[j][i]&&v[j]) ct++;
        }
        if(ct>=m){
            for(int j=1;j<=n;j++){
                if(!a[j][i]) v[j]=0;
            }
            asa+=mi[i-1];
        }else{
            continue;
        }
    }
    cout<<asa;
    return 0;
}
/*
Part of my heart was left behind that day

I remember every time I smell the rain

Asking my self what ??? means

Why not this world takes me to the heaven
*/
