#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    long long int a,n,cnt=0,cntt=0,ans=0;
    string c,s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }

    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            ++ans;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
