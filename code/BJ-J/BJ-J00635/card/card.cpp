#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int ma=0;
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[j]==a[k])ma=max(ma,k);
            }
        }
        cout<<ma<<endl;
        for(int j=max(ma,i);j<=n;j++){
            cout<<a[j]<<" ";
            b[a[j]]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
//abs(A)<abs(O)!
