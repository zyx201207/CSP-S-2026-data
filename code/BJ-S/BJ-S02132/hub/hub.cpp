#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(int ii=1;ii<=t;ii++){
        int n,k;
        cin>>n>>k;
        cout<<max(1,(n-k)/3)<<"\n";
        for(int i=1;i<n;i++){
            cin>>k>>k;
        }
    }
    return 0;
}
//I don't know what can I do for it
//I'm not good at English,but I think I need to write something for my last comptition in junior high.
//Two years ago,my OI life have been started.
//Last year,I got nothing.
//This year...
//100+100(maybe 0pts...?)+32(maybe 8pts)+0
//Can I get 1=...?
//Good luck 