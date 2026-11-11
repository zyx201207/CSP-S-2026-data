/***************
 - @GavinCQTD
***************/

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

int n;
ll m,a[500005],pre[500005];

bool check(int mid,int curi){
    // check: mid ~ i-1
    ll sum=pre[curi-1]-pre[mid-1],lth=(curi-1)-mid+1;
    return a[curi]*lth-sum<=m;
}

int main(){
    fin >> n >> m;
    for(int i=1;i<=n;i++){
        fin >> a[i];
    }
    
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    
    int ans=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i-1,ret=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                ret = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ans = max(ans,i-ret+1);
    }
    
    fout << ans << "\n";
    
    return 0;
}

