//GZ-J00160 贵阳市第三中学 严介谦
#include<bits/stdc++.h>
using namespace std;
int a[200005],table[200005],cnt[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        int f=0;
        for(int j=i;j<n;j++){
            if(f==0){
                table[0]=a[j];
                f++;
            }else{
                if(table[f-1]==a[j]){
                    table[f-1]=0;
                    f--;
                }else{
                    table[f]=a[j];
                    f++;
                }
            }
        }for(int j=1;j<=m;j++){
            for(int k=0;k<f;k++){
                if(table[k]==j){
                    cnt[j-1]++;
                    break;
                }
            }
        }
    }for(int i=0;i<m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
