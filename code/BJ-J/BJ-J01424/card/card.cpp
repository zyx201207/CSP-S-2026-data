#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000001];
long long table[5000001];
long long ans[5000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }int an=0;
    for(int x=1;x<=n;x++){
        for(int i=x;i<=n;i++){
            bool flag=0;
            for(int j=1;j<=an;j++){
                if(table[j]==a[i]){
                    for(int k=j;k<=an;k++){
                        table[k]=0;
                    }an=j-1;flag=1;table[++an]=a[i];break;

                }
            }if(!flag){
                table[++an]=a[i];
            }
        }for(int i=1;i<=an;i++){
            ans[table[i]]++;
            table[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}