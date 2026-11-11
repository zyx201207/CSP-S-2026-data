#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int ans=0,sum=0;
    s='0';
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        sum+=a[i];
    }
    for(int i=1;i<=sum/2+1;i++){
        if(s[i]!=s[sum+1-i]){
            ans++;
            s[i]=s[sum+1-i];
        }
    }
    cout<<ans;
    return 0;
}
