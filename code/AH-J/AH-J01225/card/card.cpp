#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int o=0;o<n;o++){
        int cnt=0;
        for(int i=o;i<n;i++){
            int f=0;
            for(int j=0;j<cnt;j++){
                if(b[j]==a[i]){
                    cnt=j+1;
                    f=1;
                    break;
                }
            }
            if(f==0){
                b[cnt]=a[i];
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            t[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
