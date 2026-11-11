#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200005];
int ri[200005];
int nr[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ri[0]=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ri[i]=i;
    }
    unsigned long long ans=0;
    for(int i=30;i>=0;i--){
        nr[0]=0;
        unsigned long long b=1<<i;
        for(int j=1;j<=ri[0];j++){
            if(a[ri[j]]&b)nr[++nr[0]]=ri[j];
        }
        if(nr[0]>=m){
            for(int j=0;j<=nr[0];j++){
                ri[j]=nr[j];
            }
            ans|=b;
        }
    }
    cout<<ans;

    return 0;

}
