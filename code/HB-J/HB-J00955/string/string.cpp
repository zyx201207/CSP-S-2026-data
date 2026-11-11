#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,ans;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        for(int j=0;j<m;j++)
            s+=a;
    }
    l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
            s[l]=s[r];
            ans++;
        }
        l++,r--;
    }
    cout<<ans;
    return 0;
}
