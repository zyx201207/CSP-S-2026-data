#include<bits/stdc++.h>
using namespace std;
long long ans=1,cnt;
long long z[200010],f[200010];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=ans;j<=a+ans;j++){
            z[j]=c-'0';
        }
        ans+=a;
    }
    for(int i=1;i<=ans;i++){
        cout<<z[i]<<endl;
    }
    for(int i=1;i<=ans/2;i++){
        f[i]=z[ans+1-i];
    }
    for(int i=1;i<=ans/2;i++){
        if(f[i]!=z[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
