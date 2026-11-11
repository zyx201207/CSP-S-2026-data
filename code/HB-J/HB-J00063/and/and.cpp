#include<bits/stdc++.h>
using namespace std;

long long a[10000000005];
long long s[10000000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int x=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[i]=max(a[j],s[i]);
        }
        x=x&s[i];
    }
    int cnt=0;
    while(x!=0){
        if(x%10!=0){
            cnt++;
        }
        x/=10;
    }
    cout << cnt;
    return 0;

}
