#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,q;
bool spd(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    /*cin>>n>>m;
    int a[m+1];
    for(i=1;i<=m;i++){
        a[i]=0;
    }
    for(i=1;i<=n;i++){
        sort(a+1,a+m+1);
        int an;
        cin>>an;
        if(an>a[1])a[1]=an;

    }
    int ans=a[1];
    for(i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;*/
    cin>>n>>m;
    int a[n+1];
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,spd);
    int ans=0;
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(m==2){
        int ans;
        for(i=1;i<=n;i++){
            int sum=0;
            for(j=i+1;j<=n;j++){
                sum=max(a[i]&a[j],sum);
            }
        ans=max(ans,sum);

        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    cout<<56789;




    return 0;
}
