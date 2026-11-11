#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[200005],n;
char c[200005];
char s[100000005];
int cnt=1;
void f(){
    int ans=0;
    if(cnt%2==0){
        for(int i=1;i<=cnt/2;i++){
            if(s[i]!=s[i+cnt/2]){
                ans++;
            }
        }
    }else{
        for(int i=1;i<=cnt/2-1;i++){
            if(s[i]!=s[i+cnt/2+1]){
                ans++;
                cout<<s[i]<<" "<<1<<" ";
            }
        }
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(NULL);
    cin.tie();
    cout.tie();
    cin>>n;
        bool f1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]!=c[1]){
            f1=0;
        }
    }
    if(f1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=cnt;j<cnt+a[i];j++){
            s[j]=c[i];
        }
        cnt+=a[i]+1;
    }
    f();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
