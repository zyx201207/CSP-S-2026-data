#include<bits/stdc++.h>
using namespace std;
int a[500005];
int num[300005];
int father[300005];
vector<int> s[300005];
void dfs(int in){
    for(int i=0;i<s[in].size();i++){
        dfs(s[in][i]);
        num[in] += num[s[in][i]];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    father[a[n]]=-1;
    num[a[n]]=1;
    for(int i=n-1;i>=1;i--){
        if(father[a[i]]==0){
            father[a[i]]=a[i+1];
            s[a[i+1]].push_back(a[i]);
        }
        num[a[i]]++;
    }
    dfs(a[n]);
    for(int i=1;i<=m;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
