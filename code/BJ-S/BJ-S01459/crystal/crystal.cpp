#include<bits/stdc++.h>
#define int long long
using namespace std;

int l[500005], qzh[500005];
int n,m;

bool ok(int k){
    for(int ld=1,rd;ld+k-1<=n;ld++){
        rd = ld+k-1;
        int sum = l[rd]*(k-1)-(qzh[rd-1]-qzh[ld-1]);
        if(sum<=m){
            return 1;
        }
    }
    return 0;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    sort(l+1,l+n+1);
    for(int i=1;i<=n;i++){
        qzh[i] = qzh[i-1]+l[i];
    }

    int ld=1,rd=n,mid;
    while(ld<=rd){
        mid = ((rd-ld)>>1) +ld;
   //     cout<<mid<<' ';
        if(ok(mid)){
            ld = mid+1;
      //      cout<<"yes\n";
        }
        else{
            rd = mid-1;
        //    cout<<"no\n";
        }
    }
    cout<<rd;
    return 0;
}
