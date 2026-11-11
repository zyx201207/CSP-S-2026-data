#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N=5e5+5, M=3e5+5;
int a[N];
int ans[N];
int has[M];
int main(){
    /*
    jin de le 36 fen
    zhe jie csp j gan jue hai xing
    dan ke xi wo shi yi wei chu yi de xin shou
    suan yi xia zong fen ba
    xi wang shi zhe ge fen shu
    gong 100+48+45+36=229fen hai
    */
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(has[a[j]]){
                for(int k=has[a[j]];k<=j;k++)has[a[k]]=0;
                has[a[j]]=j;
            }
            else has[a[j]]=j;
        }
        for(int i=1;i<=m;i++){
            if(has[i])ans[i]++;
            //cout<<has[i]<<" ";
        }

        //cout<<endl;
        memset(has, 0, sizeof(has));
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
/*
fu shang yi duan jie shu yu:
tian reng shi lan de, dan wo men zai yi dian dian jin bu
ji 2026 csp
*/
