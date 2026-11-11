#include<bits/stdc++.h>
using namespace std;
const int MAX=5e3+5;
int a[MAX];
int b[MAX][MAX];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=0;
    for(int i=1+num;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[num+1][j]=a[j];
        }
        num++;
    }
    for(int k=1;k<=m;k++){
        int ans=0;
        for(int i=1;i<num;i++){
            for(int j=1;j<=n;j++){
                if(b[i][j]==k){
                    ans++;
                }
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
