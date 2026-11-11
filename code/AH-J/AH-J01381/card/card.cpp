#include<bits/stdc++.h>
using namespace std;
int s[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        int a[1000000]={};
        for(int j=i;j<=n;j++){
            if(a[j]==1){
                for(int y=j-1;y>=1;y--){
                    if(s[j]==s[y]){
                        for(int q=y;q<=j-1;q++){
                            a[s[q]]--;
                        }
                    }
                }
            }else{
                a[j]++;
            }
        }
        for(int j=1;j<=m;j++){
                if(a[j]==1){
                    t[j]++;
                }

        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }

    return 0;
}
