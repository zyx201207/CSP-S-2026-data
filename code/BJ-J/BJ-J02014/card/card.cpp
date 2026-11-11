#include<bits/stdc++.h>
using namespace std;
long long a[300005],n,m,s[300005],l[300005],k=0,li[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        k=i-1;
        for(int j=i;j<=n;j++){
            if(l[a[j]]==0){
                l[a[j]]++;
                s[++k]=a[j];
            }else{
                k++;
                while(s[k]!=a[j]){
                    l[s[k]]=0;
                    s[k]=0;
                    k--;
                }
                l[s[k]]=0;
                s[k]=0;
                k--;
            }
        }
        for(int j=1;j<=m;j++){
            if(l[j]==1){
                li[j]++;
            }
            l[j]=0;
        }
        for(int j=1;j<=k;j++){
            s[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<li[i]<<" ";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
