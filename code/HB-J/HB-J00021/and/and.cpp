/*
===10:03===
max? it seems like dp...
i cannot do any dp...

no thoughts
let me take a look at t4

===11:14===
im back
now only 212pts
i need to get at least 40pts on t3?
break a leg!!

let me see whether i can use mo'ni or tan'xin
mo'ni is O(n^m)
it can only take about 20pts

5 3
31 3 1 15 7
if m=2, max=31&15=15
so it can be

4 2
15 3 1 7
is it?
max=15&7=7

likely
do it first
O(n^m) => O(n^2*m)

we can get it faster
if i<max||j<max,i&j will impossible >max
so it can take some continues

===11:55===
give up
i have no time

200+12+12=224pts?
c u afternoon

Goodnight.
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    long long ans=-1;
    if(m==2){
        for(int j=1;j<=n;j++){
            if(a[j]<ans){continue;}
            for(int k=j+1;k<=n;k++){
                if(a[j]&a[k]>ans){ans=a[j]&a[k];}
            }
        }
    }else{
        sort(a+1,a+n+1,greater<long long>());
        ans=a[1]&a[2];
        for(int i=3;i<=m;i++){ans&=a[i];}
    }
    cout<<ans;
    return 0;
}