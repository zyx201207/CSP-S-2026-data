#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],book[300005],d[500005],len,ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)book[j]=0;
        for(int j=1;j<=len;j++)d[j]=0;
        len=0;
        for(int j=i;j<=n;j++){
            if(book[a[j]]==0){
                len++;
                d[len]=a[j];
                book[a[j]]=len;
            }else{
                for(int k=book[a[j]]+1;k<=len;k++)book[d[k]]=0;
                len=book[a[j]];
            }
        }
        /*cout<<i<<" "<<len<<endl;
        for(int j=1;j<=len;j++)cout<<d[j]<<" ";
        cout<<endl;*/
        for(int j=1;j<=len;j++){
            ans[d[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
