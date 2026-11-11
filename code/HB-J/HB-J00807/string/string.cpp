#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+10;
//64
int n;
ll sum,a[N],ans[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        char y;
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            s+=y;
        }
    }
    for(int i=0,j=s.size()-1;i<s.size();i++,j--){
        if(s[i]!=s[j]){
            sum++;
        }
    }
    cout<<sum/2;
    return 0;
}
