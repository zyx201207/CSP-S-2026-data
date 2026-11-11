#include <bits/stdc++.h>
using namespace std;

long long ans,cnt=1;
int n;
char c[20000005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char cw;
        cin>>a>>cw;
        for(int i=cnt;i<cnt+a;i++){
            c[i]=cw;
        }
        cnt+=a;
    }
    for(int i=1,j=cnt-1;i<j;i++,j--){
        if(c[i]!=c[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
