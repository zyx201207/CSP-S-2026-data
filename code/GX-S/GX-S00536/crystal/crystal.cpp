#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=1;
    long long m;
    cin>>n>>m;
    long long a[n+5]={0};
    if(m==0){
        long long aa=1,c[n+5]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
            c[a[i]]++;
            aa=max(aa,c[a[i]]);
        }
        cout<<aa<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        long long r=a[i];
        int mm=m,tmp=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            mm-=(labs(a[j]-r));
            if(mm<0) break;
            tmp++;
            if(mm==0) break;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
