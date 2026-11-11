#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200001],f[200001][200001];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        int maxa=0;
        for(int i=0;i<n;i++){
            if(a[i]>maxa)maxa=a[i];
        }
        cout<<maxa;
        return 0;
    }
    if(m==n){
        int aal=a[0];
        for(int i=1;i<n;i++)aal=aal&a[i];
        cout<<aal;
        return 0;
    }
    else cout<<0;
//    fclose("string.in");
//    fclose("string.out");
    return 0;
}
