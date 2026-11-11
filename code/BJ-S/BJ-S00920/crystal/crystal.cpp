#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(a[1]<=0){
            long long c=abs(a[1]);
    for(int i=1;i<=n;i++){
        a[i]+=abs(c);
    }
    }
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';*/
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        c[i]=c[i]-c[i-1];

    }/*
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    cout<<'\n';*/
    long long x=0,y=0;
    for(int i=1;i<=n;i++){
        y=0;
        for(int j=i;j<=m;j++){
            if(b[j]-b[i]-1<=m){
                y++;
            }else{
                //cout<<b[j]<<' '<<b[i]<<' ';
                break;
            }
        }
        //cout<<y<<'\n';
        if(y>x){
            x=y;

        }
        x=max(x,y);
        //if(i=i) cout<<x<<' ';
    }
    printf("%d\n",x);
    return 0;
}
