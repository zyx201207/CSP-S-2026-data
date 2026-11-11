#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m==1){
        long long x,maxs=-1;
        for(int i=1;i<=n;i++){
            cin >> x;
            maxs=max(maxs,x);
        }
        cout << maxs << endl;
        return 0;
    }
    else if(m==n){
        long long int x,maxs=1;
        for(int i=1;i<=n;i++){
            cin >> x;
            maxs&=x;
        }
        cout <<  maxs << endl;
        return 0;
    }
    else if(m==n-1){
        long long a[200005],x=1,maxs;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            x&=a[i];
        }
        for(int i=1;i<=n;i++){
            x&=a[i];
            maxs=max(maxs,x);
            x&=a[i];
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
