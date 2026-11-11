#include<bits/stdc++.h>
using namespace std;
long long a[200001];
long long n,m,sum,num,cnt,sut=1,Max=-1;
void dfs(long long sum,long long num,long long cnt){
    if(n-sum<cnt)
    {
        return;
    }
    if(sum==0)
    {
        Max=max(num,Max);
        return;
    }
    dfs(sum-1,num&a[cnt],cnt+1);
    dfs(sum,num,cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=21;i++)
    {
        sut*=2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(m,sut-1,1);
    cout<<Max;
    return 0;
}
