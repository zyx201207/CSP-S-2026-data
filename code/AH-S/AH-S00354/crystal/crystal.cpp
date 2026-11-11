#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define int long long
int a[500001],b[500001],c[500001],e[500001];
int n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    int maxn=0,tot=0,head=1;
    int ans=0;
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
        c[i]=c[i-1]+b[i];
        tot=tot+b[i]*(i-head+1);
        ans++;
        if(tot<=m){
            maxn=max(maxn,ans-head+1);
            //cout<<i<<":"<<tot<<endl;
        }else{
            while(head<=i){
                tot-=c[i];
                c[i]-=b[head];
                //cout<<tot<<endl;
                //ans--;
                head++;
                if(tot<=m) break;

            }
            //ans++;
            //head--;
            //cout<<"jian:"<<head<<" "<<tot<<endl;
        }
        //cout<<i<<" "<<maxn<<" "<<tot<<endl;
        //cout<<b[i]<<endl;
    }

    cout<<maxn+1;
    return 0;
}
