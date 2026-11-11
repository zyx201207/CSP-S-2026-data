#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<j){
        int mn=min(a[i],a[j]);
        if(c[i]!=c[j]){
            ans+=mn;
        }
        a[i]-=mn;
        a[j]-=mn;
        if(a[i]==0) i++;
        if(a[j]==0) j--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
I want to AK csp_j !
*/
