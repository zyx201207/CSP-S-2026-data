#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        string c;
        cin>>c;
        for(long long j=0;j<a;j++)
            s+=c;
    }
    long long ans=0;
    for(int i=0,j=s.size()-1;j-i>0;i++,j--)
            if(s[i]!=s[j])
                ans++;
    cout<<ans;
    return 0;
}