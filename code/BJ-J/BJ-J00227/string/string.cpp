#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long s=0,ans=0;
    cin>>n;
    int a[200001];
    char c[200001];
    string b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=0;j<a[i];i++){
            b[s]=c[i];
            s++;
        }
    }
    for(int i=0;i<s/2;i++){
        if(b[i]!=b[s-i]){
            ans++;
        }
    }
    cout<<ans;
}
