#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char c[maxn];
string s1,s2,ss;
long long a[maxn],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ss=to_string(c[i]);
        for(int j=1;j<=a[i];j++){
            s1=s1+ss;
            s2=ss+s2;
        }
    }
    if(s1==s2)cout<<0<<"\n";
    else{
        long long m=ceil(s1.size()/2);
        for(long long i=0;i<m;i++){
            if(s1[i]!=s2[i])ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
