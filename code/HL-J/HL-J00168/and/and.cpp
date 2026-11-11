#ifndef AND_CPP_INCLUDED
#define AND_CPP_INCLUDED
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[919191];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long maxs=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
                if(i==j){
                    continue;
                }
            maxs=max(maxs,(a[i]&a[j]));
        }
    }
    cout<<maxs;
    return 0;
}//6767676767


#endif // AND_CPP_INCLUDED
