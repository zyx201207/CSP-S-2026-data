#include<bits/stdc++.h>
using namespace std;
int n;
string s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int k=0;
    while(n--){
        int t;
        char s2;
        cin>>t;
        cin>>s2;
        while(t--){
            s1[k]=s2;
            k++;
        }
    }
    int ans=0;
    for(int i=0;i<=n/2;i++) if(s1[i]!=s1[n-1-i]) ans++;
    cout<<ans;
    return 0;
}
