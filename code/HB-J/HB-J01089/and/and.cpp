#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m;
long long a[N];
long long sum;
long long mas;
long long sum1;
void dfs(int id,int se){
    if(se==0){
        mas=max(mas,sum);
        return;
    }
    if(se>n-id)return;
    dfs(id+1,se);
    sum1=sum;
    if(se==m) sum=a[id];
    else sum&=a[id];
    dfs(id+1,se-1);
    sum=sum1;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,m);
    cout<<mas;
    return 0;
}
