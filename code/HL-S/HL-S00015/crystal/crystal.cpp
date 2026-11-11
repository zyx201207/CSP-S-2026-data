#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
return a<b;
}

const int q=500030;
long long a[q],b[q];
long long calc_energy(long long x,long long y){
    return a[y]*(y-x)-b[y-1]+b[x-1];
}

int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);

int n,m;
cin>>n>>m;

if(n==1){cout<<1;return 0;}

for(int i=1;i<n;i++){
    cin>>a[i];
}

sort(a,a+n,cmp);

int tmp=0;
for(int i=0;i<n;i++){
    tmp+=a[i];
    b[i]=tmp;
}

int h=1;
for(int tgt_idx=1;tgt_idx<n;tgt_idx++){
    int be=0,en=tgt_idx;
    while(be<en){
        int mid=(be+en)/2;
        if(calc_energy(mid,tgt_idx)<=m){
            en=mid;
        }else{
            be=mid+1;
        }
    }

    h=max(h,tgt_idx-be+1);
}
cout<<h;

return 0;
}
