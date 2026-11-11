#include<bits/stdc++.h>
using namespace std;
unsigned long long n,cnt;
unsigned long long maxn,num,l[200001];
char aq,kl[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        char b;
        cin>>b;
        l[i]=a;
        kl[i]=b;
        cnt+=a;
    }
    unsigned long long le=1,ri=n,sum=0;
    while(le<ri){
        int qwq=l[le],awa=l[ri];
        if(kl[le]==kl[ri]){
            l[le]-=min(qwq,awa);
            l[ri]-=min(qwq,awa);
            sum+=min(qwq,awa)*2;
        }
        else{
            l[le]-=min(qwq,awa);
            l[ri]-=min(qwq,awa);
        }
        while(l[le]==0&&le<ri){
            le++;
        }
        while(l[ri]==0&&ri>le){
            ri--;
        }
    }
    num=(cnt-sum-l[ri])/2;
    cout<<num;
    return 0;
}
