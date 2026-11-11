#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt=0,x[200005],ans=0;
char y[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int i=1;i<=a;i++){
            cnt++;
            y[cnt]=b;
        }
    }

    int l=1,r=cnt;
    while(l<r){
        if(y[l]!=y[r]){
            ans++;
        }
        r--;
        l++;
    }
    cout<<ans;
return 0;
}