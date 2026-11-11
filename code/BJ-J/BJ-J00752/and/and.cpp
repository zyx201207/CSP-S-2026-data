#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int max_n=-1;
int a[N];
void dfs(int st,int now_num,int len,int chose){
    if(chose==0){
        max_n=max(now_num,max_n);
        return;
    }
    for(int i=st;i<=len-chose;i++){
        if(now_num==-1)dfs(i+1,a[i],len,chose-1);
        else{
            dfs(i+1,a[i]&now_num,len,chose-1);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,-1,n,m);
    cout<<max_n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
