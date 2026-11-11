#include<bits/stdc++.h>
using namespace std;
int a[5005][4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c;
    int n,m,d,q;
    cin>>n>>m>>d>>q;

    for(int i=1;i<=n;i++){
        cin>>a[i][0];
    }
    int z[20],k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>z[j];
            if(a[z[j]][1]!=0){
                cin>>a[z[j]][1];
            }else{
                cin>>a[z[j]][2];
            }

        }
    }
    for(int i=1;i<=q;i++){
        int sum=0,x,y,xi,yi;
        cin>>x>>y;
        sum+=a[x][0];
        sum+=a[y][0];
        for(int i=1;i<=n;i++){
            if(z[i]==x){
                xi=i;
            }
            if(z[i]==y){
                yi=i;
            }
        }
        for(int i=xi;i<=yi;i++){
            sum+=a[i][1];
        }
        cout<<sum<<"\n";
    }
    return 0;
}
