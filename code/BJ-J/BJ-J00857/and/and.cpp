#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int jkl[20];
int ones(long long n){
    int cnt=0;
    while(n>0){
        cnt+=n%2;
        n/=2;
    }
    return cnt;
}
int lg2(long long n){
    int cnt=0;
    while(n>1){
        cnt++;
        n/=2;
    }
    return cnt;
}
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i1,i2,i3,i4,i0;
    i1=i2=i3=i4=i0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)i0++;
        else if(a[i]==1)i1++;
        else if(a[i]==2)i2++;
        else if(a[i]==3)i3++;
        else if(a[i]==4)i4++;
        if(lg2(a[i])+1==ones(a[i])){
            jkl[lg2(a[i])]++;
        }
    }
    if(n<=20){
        sort(a+1,a+n+1);
        long long maxn=0;
        do{
            long long k=a[1];
            for(int i=2;i<=m;i++){
                k&=a[i];
            }
            maxn=max(maxn,k);
        }while(next_permutation(a+1,a+n+1));
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];return 0;
    }
    if(m==n){
        long long k=a[1];
        for(int i=2;i<=n;i++){
            k&=a[i];
            if(k==0)break;
        }
        cout<<k;
        return 0;
    }
    if(m==2){
        long long maxn=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(a[1]<=4){
        if(i4>=m)cout<<4;
        else if(i3>=m)cout<<3;
        else if(i3+i2>=m)cout<<2;
        else if(i3+i1>=m)cout<<1;
        else cout<<0;
        return 0;
    }
    int m1=0,q;
    for(int j=19;j>=0;j--){
        m1+=jkl[j];
        q=j;
        if(m1>=m)break;
    }
    cout<<(1<<q);
    return 0;
}
