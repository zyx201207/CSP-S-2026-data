#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N];
long long t[N];
int main(){
    freopen("crytal.in","r",stdin);
    freopen("crytal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m>0){
        int mn=INT_MAX;
        int id=0;
        for(int i=1;i<=n;i++){
            if(mn>a[i]){
                mn=a[i];
                id=i;
            }
        }
        a[id]++;
        m--;
    }
    for(int i=1;i<=n;i++){
        t[a[i]]++;
    }
    sort(t,t+N);
    cout<<t[N-1];
    return 0;
}
