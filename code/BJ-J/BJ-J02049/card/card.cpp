#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[300005],pos[300005],ans[300005],cnt;
long long n,m;
bool f=false;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
        pos[a[i]]=i;
        if(a[i]<a[i-1]){
            f=true;
        }
    }
    if(m==2){
        if(a[n]==1){
            cout<<n<<" "<<s[2];
        }else{
            cout<<s[1]<<" "<<n;
        }
        return 0;
    }
    if(f==false){
        for(int i=1;i<=m;i++){
            cout<<pos[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long p=i;
        while(p<=n){
            ans[a[p]]++;
            p=pos[a[p]]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
