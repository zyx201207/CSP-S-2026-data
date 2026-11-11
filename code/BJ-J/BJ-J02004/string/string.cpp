#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a){
            a--;
            s+=c;
        }
    }
    n=s.size();

    int ans=0;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            ans++;
            //cout<<"add at "<<i<<'\n';
        }
    }
    //cout<<s<<'\n';
    cout<<ans<<'\n';
    return 0;
}
