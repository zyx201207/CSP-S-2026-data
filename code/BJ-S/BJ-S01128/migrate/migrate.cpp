#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int b[5010];
int idx=0;
void f(int n,int now,int r,int d){
    if(now==r){
        b[idx++]=n;
        return;
    }
    for(int i=now+1;i<=r&&a[i]-a[now]<d;i++){
        f(n+1,i,r,d);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,cnt=0;
        cin>>n>>d;
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                f(0,l,r,d);
                int mn=1e9,num=0;
                for(int i=0;i<idx;i++){
                    if(b[i]==mn)num++;
                    else if(b[i]>mn)mn=b[i],num=1;
                }
                idx=0;
                if(num==2)cnt++;
            }
        }
        cout<<0<<endl;
    }

    return 0;
}
