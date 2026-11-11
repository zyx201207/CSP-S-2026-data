#include<bits/stdc++.h>
using namespace std;
vector<char> h;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    int a;char c;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            h.push_back(c);
        }
    }
    int ans=0;
    for(int i=0;i<h.size()/2;i++){
        if(h[i]!=h[h.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;




    return 0;
}
//2
//2 a
//3 a
