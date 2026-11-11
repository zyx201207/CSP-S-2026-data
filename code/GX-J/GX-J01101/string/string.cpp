#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t,ans=0;
    cin >>t;
    string s,s1;
    int u=0;
    for(int i=1;i<=t;i++){
        int a;
        char b;
        cin >>a>>b;
        for(int i=1;i<=a;i++){
            s[u]=b;
            u++;
        }
    }
    int j=u-1;
    for(int i=0;i<=u/2;i++){
        if(s[i]!=s[j]){
            ans++;
            s[j]=s[i];
        }
        j--;
    }
    cout<<ans;
 return 0;
}
