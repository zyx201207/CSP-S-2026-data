#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int s[t+10];
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>a[i];
            for(int k=a[i];k<=d;k++){
                s[k]=max(s[k],s[k-a[i]]+k);
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
