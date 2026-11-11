#include<bits/stdc++.h>
using namespace std;
char c[100000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0,num,now=1;
    char ch;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num>>ch;
        for(int j=1;j<=num;j++){
            c[now]=ch;
            now++;
        }
    }
    now--;
    int a=now%2?now/2+1:now/2;
    int b=now/2+1;
    while(a>0&&b<now+1){
        if(c[a]!=c[b]){
            ans++;
        }
        a--;
        b++;
    }
    cout<<ans;
    return 0;
}
