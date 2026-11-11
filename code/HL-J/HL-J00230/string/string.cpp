#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a[1000010];
    int n;
    cin>>n;
    long long ans=0;
    int a2=0;
    for(int i=1;i<=n;i++){
        int a1;
        cin>>a1;
        char s;
        cin>>s;
        for(int j=a2;j<(a2+a1);j++){
            a[j]=s;
        }
        a2+=a1;
    }

    for(int i=0;i<a2/2;i++){
        if(a[i]!=a[a2-i-1]){ans++;}
    }
    cout<<ans;
    return 0;
}
