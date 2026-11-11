#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a[MAXN];
char c[MAXN];
long long ans;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s.push_back(c[i]);
        }
    }

    for(int head=0,tail=s.size()-1;head<=tail;head++,tail--){
        if(s[head]!=s[tail]) ans++;
    }
    cout<<ans;
    return 0;
}
