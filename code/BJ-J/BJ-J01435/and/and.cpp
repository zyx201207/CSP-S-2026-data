#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],num,maxx;
string z,p,l;
void two(long long x,string s){
    s+=x%2;
    z=s;
    if(x/2!=0){
        two(x/2,s);
    }
    return;
}
void yu(long long x,long long y){
    two(y,l);
    p=z;
    two(x,l);
    long long minn=min(p.size(),z.size());
    for(int i=0;i<=minn;i++){
        if(p[i]!=z[i]){
            p[i]=0;
        }
    }
    while(p[minn]==0){
        minn--;
    }
    if(minn<=0){
        num=0;
        return;
    }
    num=p[minn]*2+p[minn-1];
    minn--;
    while(minn--){
        num=num*2+p[minn-1];
    }
    num+=p[minn+1];
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }else if(m==n){
        for(int i=2;i<=n;i++){
            yu(a[i],a[i-1]);
            a[i]=num;
        }
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                yu(a[i],a[j]);
                maxx=max(maxx,num);
            }
        }
    }
    cout<<maxx;
    return 0;
}
