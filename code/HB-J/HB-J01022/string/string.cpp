#include<bits/stdc++.h>
using namespace std;
const int mx=2E5+10;
int a[mx];
char c[mx],s[mx];
int n,l,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=l;j<=l+a[i]-1;j++) s[j]=c[i];
        l+=a[i];
    }
    for(int i=0,j=l-1;i<l/2;i++,j--){
        if(s[i]!=s[j]){
            ans+=1;
        }
    }cout<<ans;
    return 0;
}//aaa,What is T3 and T4
//I forget how can I write DFS
//I will do better in the next year!
