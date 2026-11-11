#include<bits/stdc++.h>
using namespace std;
int n;
int s[200005];
char v[200005];
long long h=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>v[i];
    }
    long long l=1,r=n;
    while(l<r){
        if(v[l]!=v[r]){
            h+=min(s[l],s[r]);
        }
        if(s[l]>s[r])s[l]-=s[r],r--;
        else if(s[r]>s[l])s[r]-=s[l],l++;
        else r--,l++;
    }
    cout<<h;
    return 0;
}
