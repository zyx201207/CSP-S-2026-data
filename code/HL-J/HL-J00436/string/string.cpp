#include<bits/stdc++.h>
using namespace std;
int s[1000001],num=0,num1=10000000;
char c[1000001],ans[10000001],ans1[10000001];
void dfs(){
    for(int x=0;x<strlen(ans);x++){
        ans1[x]=ans[x];
    }
    num=0;
    for(int i=0;i<strlen(ans);i++){
        for(int j=strlen(ans)-1;j>=i;j--){
            if(ans[i]!=ans[j]){
                ans1[j]==ans1[i];
                num++;
            }
        }
        num1=min(num,num1);
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    int q=0;
    for(int i=0;i<n;i++){
    cin>>s[i]>>c[i];
    for(int x=q;x<q+s[i];x++){
        ans[x]=c[i];
    }
    q+=s[i];
    }
    cout<<ans;
    int dc=1;
    for(int i=0;i<strlen(ans);i++){
        for(int j=strlen(ans)-1;j>=i;j--){
            if(ans[i]!=ans[j]){
                dc=0;
                break;
            }
        }
        if(dc==0) break;
    }
    if(dc==1){
        cout<<"0";
        return 0;
    }
    dfs();
    cout<<num1;
    return 0;
    }
