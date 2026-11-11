#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b,mx,minx,y;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        mx=max(x,mx);
        minx=min(x,minx);
        a[x+500000]++;
    }
    for(int i=minx+500000;i<=mx+500000;i++){
        int j=i-1,m1=m;
        long long c[1000001]={};
        for(int k=minx+500000;k<=mx+500000;k++){
            c[k]=a[k];
        }
        while(m1>0&&j>=minx){
            if(c[j]>0){
                if(i-j<=m1){
                    m1-=i-j;
                    c[j]--;
                    c[i]++;
                }
                else break;
            }
            else j--;
        }
        b=max(c[i],b);
        if(c[i]>b)y=i;
    }
    cout<<b;
    //cout<<n<<' '<<m<<3;
    return 0;
}
