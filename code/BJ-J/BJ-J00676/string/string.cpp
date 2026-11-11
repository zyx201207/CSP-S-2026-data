#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
     int n,ans;
     map<char,int> w[200010];
     cin>>n;
     string u;
     for(int i=1;i<=n;i++){
        char q;
        int p;
        cin>>p;
        for(int j=1;j<=p;j++){
            u=u+q;
        }
     }
     int m=n/2;
     int l=strlen(u);
     for(int i=1;i<=m;i++){
        if(u[i]!=u[l-i+1]){
            ans++;
        }
     }
     cout<<ans;
    return 0;
}
