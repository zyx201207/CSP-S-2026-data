#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,a[500005],ans=0,t=0,m,ma=0,y=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==0){
        for(int i=0;i<n;i++){
            y=0;
            for(int j=0;j<n;j++){
                if(a[i]==a[j])y++;
            }
            if(y>ma && y>=2)ma=y;
        }
        cout<<ma;
        return 0;
    }
    for(int i=0;i<n;i++){
        long long l=m;
        t=0;
        for(int j=i;j<n;j++){
            t++;
            if(a[j+1]-a[j]<=l){
                l-=a[j+1]-a[j];
            }
            else{
                t=0;
                break;
            }
        }
        if(t>ans)ans=t;
    }
    cout<<ans;
    return 0;
}
