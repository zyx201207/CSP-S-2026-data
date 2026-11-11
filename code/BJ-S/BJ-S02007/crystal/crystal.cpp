#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN],s[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int ci=3;

        if((s[i] + m) % a[ci] == 0){
            cnt=i+1;
            break;
        }
       if(ci<i-1){
            ci++;
        }
    }
    for(int i=cnt+1;i<=n;i++){
        if(a[cnt]==a[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
