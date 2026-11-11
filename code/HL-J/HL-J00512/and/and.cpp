#include <bits/stdc++.h>
using namespace std;
int a[220000];
vector<int> b,c;
int main(){
#ifndef HCX
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b.push_back(a[i]);
    }
    for(int i=30;i>=0;i--){
        int mask=1<<i;
        int cnt=0;
        for(int j=0;j<b.size();j++){
            if(b[j]&mask)cnt++;
        }
        if(cnt>=m){
            c.clear();
            for(int j=0;j<b.size();j++){
                c.push_back(b[j]);
            }
            b.clear();
            for(int j=0;j<c.size();j++){
                if(c[j]&mask){
                    b.push_back(c[j]);
                }
            }
        }
    }
    // li lun shang qu shen me shun xu dou bu ying xiang da an
    sort(b.begin(),b.end(),greater<int>());
    int ans=b[0];
    for(int i=0;i<m;i++){
        ans&=b[i];
    }
    cout<<ans<<"\n";
    return 0;
}
// compile:
// g++ and.cpp -o and -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow 2> log.txt
// debug
// g++ and.cpp -o and -fsanitize=address,undefined -g -DHCX -std=c++14 -Wall -Wextra -Wconversion -Wshadow 