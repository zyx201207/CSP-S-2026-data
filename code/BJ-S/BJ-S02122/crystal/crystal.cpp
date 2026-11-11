
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ai=0,maxx=-100000000000001,minn=100000000000001,ans=0,num=0;
    bool flag;
    cin>>n>>m;
    long long a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(minn>a[i]) minn=a[i];
    }
    for(int i=0;i<n;i++){
        if(abs(a[i]-minn)<=m){
            b[ai]=a[i];
            ai++;
        }
    }
    sort(b,b+ai);
    for(int j=0;j<ai;j++){
        flag=true;
        for(int i=0;i<ai;i++){
            ans+=abs(b[ai]-b[i]);
            if(ans>m){
                ai--;
                ans=0;
                num=0;
                flag=false;
                break;
            }
            else num++;
        }
        if(flag) break;
    }
    cout<<num+1;
    return 0;
}
