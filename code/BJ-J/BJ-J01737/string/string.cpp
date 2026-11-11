#include<bits/stdc++.h>
using namespace std;
int n,nn[200010],lendz=1,lendcnt;
string str,a;
long long total=1,lend,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nn[i]>>str[i];
        for(int j=1;j<=nn[i];j++){
            a[total]=str[i];
            total++;
        }
    }
    lend=total/2;
    for(int i=1;i<=lend;i++){
        if(a[i]!=a[total-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}