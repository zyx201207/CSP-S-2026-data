#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

int n,m;

int a[500005];

int p[500005];

int k;

int c[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(p,0,sizeof(p));
        k=0;
        for(int j=i;j<=n;j++){
            bool f=0;
            int t;
            for(int q=1;q<=k;q++){
                if(p[q]==a[j]){
                    f=1;
                    t=q;
                    break;
                }
            }
            if(f){
                k=t;
            }else{
                    p[++k]=a[j];
            }
        }
        for(int q=1;q<=k;q++){
            c[p[q]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
/*
Part of my heart was left behind that day

I remember every time I smell the rain

Asking my self what ??? means

Why not this world takes me to the heaven
*/
