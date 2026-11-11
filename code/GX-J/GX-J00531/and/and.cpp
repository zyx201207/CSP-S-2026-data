#include<bits/stdc++.h>
using namespace std;
long long n,m,d=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long im,jm;
    for(int i=0;i<n;i++){
        for(int j=i;i<n;i++){
            long long s=a[i]&a[j];
            if(d<s){
                d=s;
                im=i;
                jm=j;
            }
        }
    }

    long long f=-1;
    a[jm]=-1;
    while(1){
        bool flag=0;
        a[im]=-1;
        for(int i=0;i<n;i++){
            if(a[i]==-1) continue;
            flag=1;
            long long s=d&a[i];
            if(s>f){
                f=s;
                im=i;
            }
        }
        d=f;
        if(flag==1) break;
    }
    cout<<d;
    return 0;
}
