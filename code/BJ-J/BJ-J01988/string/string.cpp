#include <bits/stdc++.h>

using namespace std;
vector<char> s;
long long n,ans,len;
long long a[20001];
char c[20001];
int main()
{
    freopen("string.in","r",stdin);freopen("string.out"."w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];++j) s.push_back(c[i]);
        len+=a[i];
    }
    //cout<<len<<endl;
    for(int i=0;i<len;i++){
         //   cout<<s[i]<<endl;
        if(s[i]!=s[len-i-1]&&i<=len-i-1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
