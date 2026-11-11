#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int _max=0,y;
    int flag=1;
    int r=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(r*2==i)r=r*2;
        if(a[i]!=i-1)flag=0;
        _max=max(a[i],_max);
        if(i!=1)y=y&a[i];
        else y=a[i];
    }
    if(m==1){
        cout<<_max;
        return 0;
    }
    if(flag&&r==n){
        int s=1;
        for(int i=1;i<=n;i++){
            if(s*2==i){
                s=i;
            }if(s>=m){
                break;
            }
        }cout<<n-s;
        return 0;
    }
    if(m==2){
        int c=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                c=max(c,a[i]&a[j]);
            }
        }cout<<c;
        return 0;
    }
    if(m==n){
        cout<<y;
        return 0;
    }
    int x=0;
    int b[m+1]={};
    for(int i=1;i<=m;i++){
        b[i]=i;
    }
    int p=m;
    int l=n;
    while(p>0){
        int ab=b[1];
        int t=a[ab];
        for(int j=2;j<=m;j++){
            ab=b[j];
            t=t&a[ab];
        }x=max(x,t);
        b[p]++;
        if(b[p]>l){
            b[p]=l;
            p--;
            l--;
            b[p]++;
        }
    }
    cout<<x;
    return 0;
}
