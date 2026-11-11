#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[200005];
char c[200005],ans[1000000000]fans[1000000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,now=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin<<a[i]<<c[i];
        for(int j=i;j<=a[i];j++)    ans[j]=c[i];
    }
    for(int i=n;i>=1;i--){
        fans[i]=ans[now];
        now++;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==fans[i]){
            if(i==n)    cout<<cnt;
            else    continue;
        }
        else    break;
    }
    cout<<cnt
    return 0;
}