#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans=1,head=0,tail=0,b=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w".stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    int o=n/2+1;
    int p=a[o];
    for(int i=1;i<=o-1;i++){
        head+=a[i];
        b++;
    }
    head/=b;
    b=0;
    for(int i=o+1;i<=n;i++){
        tail+=a[i];
        b++;
    }
    tail/=b;
    if(p-head<=tail-p){
        for(int i=o;i>=1;i--){
            if(m>=p-a[i]){
                m-=p-a[i];
                a[i]+=p-a[i];
            }

        }
        for(int i=1;i<=n;i++){
            if(a[i]==p){
                ans++;
            }
        }
        cout<<ans-1;
    }
    else
    {
        int i=n-1;
        while(1){
            int k=a[n]-a[i];
            if(m>k && k!=0){
                a[i]+=k;
                m-=k;
            }else{
                break;
            }
            i--;
        }
        for(int i=1;i<=n;i++){
            if(a[n]==a[i]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}