#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
#define ll long long
ll n,a[N],L,ans=0;
char c[N];
string S;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++) S=S+c[i];
    }
    S=" "+S;
    
    int l,r;
    if(L%2==0){
        l=L/2,r=L/2+1;
    } else l=r=L/2+1;
    while(l>0 && r<L+1){
        if(S[l]!=S[r]){
            ans++;
        }
        l--; r++;
    }

    cout<<ans;
    return 0;
}
