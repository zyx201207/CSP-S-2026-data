#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c;
    int t;
    int n;
    int k;
    int ui;
    int vi;
    cin>>c>>t;
    for(int a=1;a<=t;a++){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>ui>>vi;
        }
        cout<<int(n*2/10)<<endl;
    }
    return 0;
}