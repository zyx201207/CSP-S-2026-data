#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int n,m;
int maxn=-1;
void dfs(int i,int c=0,int answer=-1){
    if (c==m){
        maxn=max(maxn,answer);
        return;
    }
    if (i==n+1) return;
    dfs(i+1,c,answer);
    if (answer==-1)
        dfs(i+1,c+1,a[i]);
    else dfs(i+1,c+1,answer&a[i]);
}
int bit(int x){
    int sum=0;
    while (x){
        x&=x-1;
        sum++;
    }
    return sum;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    if (m==n){
        int answer=a[1];
        for (int i=2;i<=n;i++)
            answer&=a[i];
        cout<<answer<<endl;
    }else if (n<=20||m==2||pow(n,m)<=5e8){
        dfs(1);
        cout<<maxn<<endl;
    }else if (m==1){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1]<<endl;
    }else if (m==n-1){
        sort(a+1,a+n+1,greater<int>());
        int answer=a[1];
        for (int i=2;i<n;i++)
            answer&=a[i];
        cout<<answer<<endl;
    }else {
        sort(a+1,a+n+1,[&](int a,int b){
            if (bit(a)!=bit(b)) return bit(a)>bit(b);
            return a>b;
        });
        int answer=a[1];
        for (int i=2;i<=m;i++)
            answer&=a[i];
        cout<<answer<<endl;
    }
    return false;
}
