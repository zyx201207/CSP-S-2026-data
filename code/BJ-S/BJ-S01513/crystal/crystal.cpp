#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

ll n,m;

ll a[500005];

ll d[5];

void ck(int x){
    ll t=m;
    d[0]=d[1]=d[2]=d[3]=d[4]=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x){
            if(t>=x-a[i]){
                t-=x-a[i];
            }else{
                d[0]++;
            }
        }else if(a[i]>x){
            d[1]++;
        }
    }
    return;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll mx=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            ck(a[i]);
            mx=max(mx,n-d[0]-d[1]);
        }
        cout<<mx;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll g=a[2]-a[1];
    ll q=g;
    ll sas=1;
    while(1){
        if(sas>=n||m<g){
            break;
        }
        m-=g;
        sas++;
        g+=q;
    }
    cout<<sas;
    return 0;
}
