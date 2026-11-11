#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
//linjingxuan is gay
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n;
ll scnt[N],sum,mid;
char slist[N];
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>scnt[i]>>slist[i];
        sum+=scnt[i];
    }
    mid = sum/2;
    if(sum%2)mid++;
    int l = 1,r = n;
    ll start = 1,lcnt = scnt[1],rcnt = scnt[n],ans = 0;
    while(l<r){
        if(slist[l]!=slist[r]){
            ans += (min(rcnt,lcnt)-start+1);
        }
        start = min(lcnt,rcnt)+1;
        if(start == lcnt+1){
            l++;
            lcnt += scnt[l];
        }
        if(start = rcnt+1){
            r--;
            rcnt += scnt[r];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
