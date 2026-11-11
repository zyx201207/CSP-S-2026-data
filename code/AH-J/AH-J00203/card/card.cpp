#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            if(t[a[j]]>i){
                t[a[j]]--;
                int pos=0x3f3f3f3f;
                for(int k=i;k<j;k++){
                    if(a[k]==a[j])pos=k;
                    if(k>pos)t[k]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
