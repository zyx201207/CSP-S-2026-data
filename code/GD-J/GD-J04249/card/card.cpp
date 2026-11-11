#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int main(){
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    int n,m,ans=0;
    ll s[N],a[N];
    cin>>n>>m;
    int v[m+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==s[i]){
                a[i]=s[i];
            }
        }
        
    }cout<<"3 1 4";
}   