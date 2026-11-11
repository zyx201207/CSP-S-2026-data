#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string c="";
    for(long long i=1;i<=n;i++){
        long long q;
        cin>>q;
        char w;
        cin>>w;
        for(long long i=1;i<=q;i++){
            c+=w;
        }
    }
    long long l=c.length();
    long long sum=0;
    for(long long i=0;i<=l/2-1;i++){
        long long j=l-i-1;
        if(c[i]!=c[j]){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
