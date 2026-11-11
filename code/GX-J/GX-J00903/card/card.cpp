#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100005],b[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[j]==a[i]){
                for(int k=0;k<=i;k++){
                    a[i]=0;
                    b[i]++;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
