#include <bits/stdc++.h>
using namespace std;
#define ll long long;
const int MAX_N=2*1e5;
int a[MAX_N];
int n,m,maxn=-1;
int dfs(int nowi,int lm,int i){// nowi表示现在的i的数值，lm表示还需要和多少个数按为与,i表示要在a数组中i后面的数中去寻找
    if(lm==2){//特判m==2时要出结果
        int maxd=-1;
        for(int j=i+1;j<=n;j++){
            maxd=max(maxd,nowi&a[j]);
        }
        return maxd;
    }
    int maxd=-1;
    for(int j=i+1;j<=n;j++){
        maxd=max(maxd,nowi&dfs(nowi&a[j],m-1,j));
    }
    return nowi&maxd;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-m+1;i++){
        maxn=max(maxn,dfs(a[i],m,i));
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
