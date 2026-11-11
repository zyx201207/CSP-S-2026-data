#include<bits/stdc++.h>
int n,m[100012];
long long cnt=0;
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    char c[100015];
    for(int i=1;i<=n;i++){
        cin>>m[i];
        cin>>c[i];

    }
    bool f=true;
    for(int i=1;i<n;i++){
        if(c[i]!=c[i+1]){
            f=false;
            break;
        }
    }
    if(f==true){
        cout<<0;
        return 0;
    }
    int a=n/2;
    for(int i=1;i<=a;i++)
    {
        if(c[i]==c[n-i+1])
        {
            cnt+=abs(m[i]-m[n-i+1]);
        }
        else{
            int b=min(m[i],m[n-i+1]);
            cnt+=b;
        }
    }
    cout<<cnt;
    return 0;
}
