#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int m;
    char c;
    string s,t;
    for(int i=0;i<n;i++){
        cin>>m>>c;
        for(int j=0;j<m;j++)
            s+=c;
    }
    int u=s.size();
    for(int i=u-1;i>=0;i--)
        t+=s[i];
    int sum=0;
    for(int i=0;i<u;i++){
        if(t[i]!=s[i])
            sum++;
    }
    cout<<sum;
    return 0;
}
