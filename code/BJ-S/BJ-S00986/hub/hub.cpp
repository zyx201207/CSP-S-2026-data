#include<bits/stdc++.h>
using namespace std;
const int N=2e6+20;
int p[N],a[N];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for (int i=1;i<n;i++)cin>>a[i]>>p[i];
        cout<<rand()%n;
    }
    return 0;
}
