#include<bits/stdc++.h>
using namespace std;
int s[200005];
int a[35];
bool f=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;
    long long cnt=0,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    cout<<s[n];
    return 0;
}
