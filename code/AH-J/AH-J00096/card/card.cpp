#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],sum[300005];
int jiyi[300005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int p=1;
        for(int j=i;j<=n;j++){
            b[p]=a[j];
            if(jiyi[b[p]]>0){
                for(int q=jiyi[b[p]]+1;q<=n;q++){
                    b[q]=0;
                    jiyi[b[q]]=0;
                }
            }
            else{
                jiyi[b[p]]=p;
            }
        p++;
        }
        for(int j=1;j<=p;j++){
            sum[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<sum[m]<<" ";
    cout<<'\n';
    return 0;
}
