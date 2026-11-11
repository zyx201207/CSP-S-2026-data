#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,len;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200009];
    char c[200009];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s[cnt]=c[i];
            cnt++;
        }
        len+=a[i];
    }
    //for(int i=0;i<len;i++)  cout<<s[i]<<" ";
    int ans=0;
    for(int i=0;i<=(len+1)/2-1;i++){
        if(s[i]!=s[len-i-1])  ans++;
    }
    //cout<<len<<endl;
    cout<<ans;
    return 0;
}
