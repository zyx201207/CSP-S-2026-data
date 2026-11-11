#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10,MA=1e6;
int a[N];
char c[N];
int maxn;
long long sum;
bool flag=true;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            flag=false;
        }
        break;
    }
    long long cnt=maxn*n;
    if(cnt<=MA){
        string s="";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        int ans=0;
        int m=s.size();
        for(int i=0;i<(m+1)/2;i++){
            if(s[i]!=s[m-i-1]){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(flag){
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(c[i]!=c[n-i+1]){
                ans+=min(a[i],a[n-i+1]);
                a[n-i+1]-=min(a[i],a[n-i+1]);
                if(a[i]<=a[n-i+1]){
                    continue;
                }else{
                    n--;
                    i--;
                }
            }
        }
        cout<<ans;
    }
    string s="";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    if(cnt>100000000){
        return 0;
    }
    long long ans=0;
    long long m=s.size();
    for(long long i=0;i<(m+1)/2;i++){
        if(s[i]!=s[m-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
