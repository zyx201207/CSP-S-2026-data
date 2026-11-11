#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500010],ans[500010],a[500010];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long l=2;
        s[1]=a[i];
        for(int j=i+1;j<=n;j++){
            s[l]=a[j];
            for(int k=1;k<l;k++){
                if(s[l]==s[k]){
                    l=k;
                    break;
                }
            }
            l++;
        }
        l--;
        for(int j=1;j<=l;j++){
            ans[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
