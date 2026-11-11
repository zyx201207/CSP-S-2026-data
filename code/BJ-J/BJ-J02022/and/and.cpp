#include <bits/stdc++.h>
using namespace std;

struct shu{
    long long shi;
    long long er;
};

long long turn(int x){
    long long b=1;
    long long y=0;
    while(x!=0){
        if(x%2==1) y+=b;
        b*=10;
        x/=2;
    }
    return y;
}

bool cmp(shu p,shu q){
    return p.er>q.er;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    shu a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].shi;
        a[i].er=turn(a[i].shi);
    }
    sort(a,a+n,cmp);
    long long ans=a[0].shi;
    for(int i=0;i<m;i++) ans&=a[i].shi;
    cout<<ans;
    return 0;
}