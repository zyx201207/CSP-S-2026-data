#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
bool book[100005];
int ans[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            b[i]=a[i];
            book[i]=false;
        }
        int m=0;
        for(int i=t;i<=n;i++){
            bool flag=false;
            for(int j=1;j<=m;j++){
                if(b[j]==a[i]){
                    m=j;
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                m++;
                b[m]=a[i];
            }
        }
        for(int i=1;i<=m;i++){
            if(book[b[i]]==false){
                ans[b[i]]++;
                book[b[i]]=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
