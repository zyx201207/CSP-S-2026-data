#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string x;
    long long cnt;
    long long a[200005];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt+=a[i];
        char m;
        cin>>m;
        for(int j=0;j<a[i];j++){
            string x;
            x+=m;
        }
    }
    int cc;
    for(int i=0;i<cnt;i++){
        if(x[i]==x[cnt-i])
        cc++;
    }
    if(cc=cnt)cout<<0;
return 0;
}
