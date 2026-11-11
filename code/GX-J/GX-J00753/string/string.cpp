#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    int a;
    vector<long long>c;
    char b;
    cin>>n;
    for(long long i=0;i<n;i++){
        scanf("%d",&a);
        cin>>b;
        for(long long j=0;j<a;j++){
            c.push_back(b);
        }
    }
    for(long long i=0;i<c.size()/2;i++){
        if(c[i]!=c[c.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
