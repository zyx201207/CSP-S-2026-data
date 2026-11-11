#include <bits/stdc++.h>
using namespace std;
long long n,m,small=500000005;
int a[500005],b[500005];
int main(){
    cin>>n>>m;
    long long sum=0,d=0,q=0,flag;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        d+=a[i];
    }
    d/=n;
    for (int i=1;i<=n;i++){
        if (a[i]==d){
            b[i]=0;
            continue;
        }
        if (a[i]>0){
            if (a[i]>d){
                b[i]=a[i]-d;
            }
            else if (a[i]<d){
                b[i]=d-a[i];
            }
        }
        if (a[i]<=0){
            b[i]=d-a[i];
        }
    }
    for (int i=1;i<=n;i++){
        if (b[i]<=small){
            small=b[i];
        }
    }
    for (int i=1;i<=n;i++){
        if (b[i]==small){
            flag=a[i];
        }
    }
    for (int i=1;i<=n;i++){
        if (m==0){
            break;
        }
        q=i;
        if (a[i]<flag&&flag-a[i]<=m){
            m-=d-a[i];
            sum++;
            continue;
        }
        else if (a[i]==flag){
            sum++;
            continue;
        }
        else {
            continue;
        }
    }
    for (int i=q+1;i<=n;i++){
        if (a[i]==flag){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
