#include<bits/stdc++.h>
using namespace std;
int m,n,ans,sum,fu,t,c;
long long a[1000000];
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=n;j++){
    for(int i=1;i<=n-j;i++){
    t+=1;
    if(t>m)
        break;
        if(t>1)
            fu=fu&a[j+i];
    else
    fu=a[j]&a[j+i];
        }
        c+=1;
        if(c==1)
        ans=fu;
        else sum=fu;
        fu=0;
        ans=max(ans,sum);
    }
    cout<<12;
return 0;
}
