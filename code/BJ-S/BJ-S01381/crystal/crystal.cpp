#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+7;
int n,m;
int a[N];
int aver,pos;
int ans = 0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += a[i];
    }
    aver = sum/n;
    int ss;
    int op = m;
    for(int i = 1;i <= n;i++){
        ss = min(ss,abs(a[i]-aver));
        if(a[i]-aver==ss) pos = i;
        if(i<=pos){
            a[i]++;
            op--;
            if(a[i]==a[pos]) ans++;
            if(a[i]>=a[pos]){
                a[i]--;
                op++;
                ans++;
            }
            if(op==0) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
