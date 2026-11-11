#include<bits/stdc++.h>
using namespace std;
unsigned long long a[1000005],d=0,g=0;
unsigned long long f(unsigned long long x,unsigned long long y){
    unsigned long long s=0,i=0;
    while(x>0||y>0){
        int o=x%2,p=y%2;
        if(o==1 && p==1){
            s+=pow(2,i);
        }
        i++;
        x/=2;
        y/=2;
    }
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);

    cin.tie(0);
    int l=0,e=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,n+a+1);
    d=a[n];
    for(int i=1;i<=m;i++){
        d=f(d,a[n-i]);
    }

    cout<<d;
    return 0;
}

