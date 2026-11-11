#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct jyc{
    long long yinum;
    long long num;
    long long llen;
}a[N];
int er(long long a0){
    long long sum=0;
    while(a0>0){
        if(a0%2==1) sum++;
        a0/=2;
    }
    return sum;
}
int len(long long a0){
    long long sum=0;
    while(a0>0){
        sum++;
        a0/=2;
    }
    return sum;
}
bool cmp(jyc x,jyc y){
    if(x.llen==y.llen){
        return x.yinum>y.yinum;
    }
    return x.llen>y.llen;
}
long long n,m,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].num;
        a[i].yinum=er(a[i].num);
        a[i].llen=len(a[i].num);
    }

    sort(a,a+n,cmp);
    ans=a[0].num;
    for(int i=1;i<m;i++){
        ans&=a[i].num;
    }
    cout<<ans;
}


