#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[10000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t,c;
    cin>>c>>t;
    int s[t+10];
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            s[abs(a[i]-b[i])]++;
        }
    }
    for(int i=0;i<t;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
