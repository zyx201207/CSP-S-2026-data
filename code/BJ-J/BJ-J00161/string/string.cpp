#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],cnt;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int li=1,ri=n;
    while(li<ri){
        int w=min(a[li],a[ri]);
        a[li]-=w;
        a[ri]-=w;
        cnt+=(c[li]!=c[ri])*w;
        if(!a[li])li++;
        if(!a[ri])ri--;
    }
    cout<<cnt;
    return 0;
}
