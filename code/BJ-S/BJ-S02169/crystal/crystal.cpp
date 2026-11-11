#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a[600005],n,q,j,x,ans=0,sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(a[i+1]==a[i]||i<=ans)continue;
        q=m;
        j=i;
        sum=0;
        while(j>0){
            x=a[i]-a[j--];
            if(q-x>=0){
                q-=x;
                sum+=1;
            }
            else{
                break;
            }
        }
        if(sum>ans)ans=sum;
    }
    cout<<ans;
    return 0;
}
