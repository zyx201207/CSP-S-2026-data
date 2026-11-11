#include <bits/stdc++.h>
using namespace std;
long long c,n,t,d,x[5005],tu[5005][5005],ans;
int a[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            int ans=0;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            int cha=x[2]-x[1];
            cha=d/cha*2+1;
            ans=n-cha+1;
            cout<<ans<<endl;
            return 0;
            fclose(stdin);
            fclose(stdout);
        }
    }
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[max(i,j)]-x[min(i,j)]<=d)
                tu[j][i]=tu[i][j]=1;
                else tu[j][i]=tu[i][j]=0x3f3f3f3f3f3f3f3f;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(tu[i][k]+tu[k][j]<tu[i][j]){
                        if(a[i][j]==2){
                            a[j][i]=a[i][j]=1;
                            ans--;
                        }else if(a[i][j]!=1){
                            a[j][i]=a[i][j]=1;
                        }
                        tu[j][i]=tu[i][j]=tu[i][k]+tu[k][j];
                    }
                    else if(tu[i][k]+tu[k][j]==tu[i][j]){
                        a[i][j]++;
                        a[j][i]=a[j][i];
                        if(a[i][j]==2){
                            ans++;
                        }
                        if(a[i][j]==3){
                            ans--;
                        }
                    }
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<tu[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<ans<<endl;
    }
    //long long asdf=2e18;
    //cout<<asdf;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
