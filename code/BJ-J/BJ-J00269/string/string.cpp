#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long nt=0;
    string s;
    char c;
    int t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>c;
        nt+=t;
        s=s+string(t,c);
    }
    nt/=2;
    int ans=0;
    for(long long i=0;i<nt;i++){
        if(s[i]!=s[nt-i-1]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
