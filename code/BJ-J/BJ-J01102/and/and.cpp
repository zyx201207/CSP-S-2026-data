#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
int dfs(int h,int g,int i){
    if(i>=n&&g<m){
        return 0;
    }
    else if(g>=m){
        return h;
    }


    cout<<h<<' '<<g<<' '<<i<<endl;
    max(dfs(h,g,i+1),dfs(h&a[i],g+1,i+1)&a[i]);
    g++;


}
int main(){
    freopen("and1.in","r",stdin);
    freopen("and1.ans.1","w",stdout);
    cin>>n>>m;
    int o=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>o){
            o=a[i];
        }
    }

    cout<<dfs(o,1,2);











    return 0;
}



