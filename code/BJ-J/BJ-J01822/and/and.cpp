#include<bits/stdc++.h>
using namespace std;
    int n,m;
    long long a[200005],maxx=0,sum;
    bool ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)sum=a[i];
        else sum=sum and a[i];
        maxx=max(maxx,a[i]);

    }
    if(m==1){cout<<maxx;return 0;}
    if(m==n){cout<<sum;return 0;}
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                //long long t=a[i] and a[j];
                //ans=max(ans,t);
                cout<<a[i] and a[j] ;
                cout<<' '<<ans<<endl;
                if(ans<a[i] and a[j])ans=a[i] and a[j];
            }
        }
        cout<<ans;
        return 0;
    }

return 0;}
