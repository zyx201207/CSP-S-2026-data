#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int cards[500005]={};
    for(int i=0;i<n;i++){
        cin >> cards[i];
    }
    int ans[300005]={};
    for(int i=0;i<n;i++){//ju shu
        int a[500005]={};
        int cnt=0;
        for(int j=i;j<n;j++){//pai shu
            int x=cards[j];
            bool g=1;
            int y=-1;
            for(int z=0;z<cnt;z++){//chong fu
                if(x==cards[z]){
                    g=0;
                    y=z;
                }
            }
            if(g){
                a[cnt]=x;
                cnt++;
            }
            else{
                for(int k=y;k<cnt;k++){
                    a[k]=0;
                    cnt--;
                }
                a[cnt]=x;
            }
        }
        for(int j=0;j<n;j++){
            ans[a[j]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
