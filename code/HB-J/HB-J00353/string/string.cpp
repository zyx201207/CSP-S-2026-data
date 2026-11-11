#include<bits/stdc++.h>
using namespace std;
int n,a,cnt,cnt1,ans;
char s,s1[1000005];
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>s;
        cnt+=a;
        for(int j=cnt-a+1;j<=cnt;j++){
            s1[j]=s;
        }
    }

    if(cnt%2==1)cnt1=cnt/2+1;
    else cnt1/=2;
    for(int i=1;i<=cnt1;i++){
        if(s1[i]!=s1[cnt-i])ans++;
    }
    cout<<ans;
    return 0;
}
