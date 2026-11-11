#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N]={0},c[N]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int cnt=1;
            int b[N]={0};
        for(int j=i;j<=n;j++){
            for(int k=1;k<=j-1;k++){
                if(b[k]==a[j]){
                    for(int o=k;o<=cnt;o++){
                       b[o]=0;
                    }
                    cnt=k;
                    break;
                }

            }
            b[cnt]=a[j];
            cnt++;
        }
        int d[N]={0};
        for(int j=1;j<=cnt;j++){
            d[b[j]]++;
        }
        for(int j=1;j<=m;j++){
            if(d[j]!=0) c[j]++;
        }
    }
        for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
