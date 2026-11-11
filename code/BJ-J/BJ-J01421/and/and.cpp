#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-9999999,b[200005],pos;
bool f;
void work1()
{
    for(long long i=1;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
}
void work2(){
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(i!=j) ans=max(ans,a[i]&a[j]);
        }

    }
    cout<<ans;
}
void workn()
{
    ans=a[1];
    for(long long i=2;i<=n;i++){
        ans=ans&a[i];
    }
    cout<<ans;
}
void work3(){
    for(long long i=1;i<=n;i++){
            long long s=0;
            pos=0;
            memset(b,0,sizeof(b));
            for(long long j=1;j<=n;j++){
                if(i!=j) b[++pos]=a[j];
            }
            s=b[1];
            for(long long j=1;j<=pos;j++)
                s=s&b[j];
            ans=max(ans,s);
        }
    cout<<ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    if(m==1){
        work1();
        return 0;
    }
    else if(m==2){
        work2();
        return 0;
    }
    else if(m==n){
        workn();
        return 0;
    }
    cout<<1;
}