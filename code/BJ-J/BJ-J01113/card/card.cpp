#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+2;
int n,m,a[MAXN],ans[2000],x;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ans[a[n]]=n;
        for(int i=n;i>=1;i--)
            if(a[i]!=a[n]){
                x=i;
                break;
            }
        for(int i=x;i>=0;i--){
            if(a[i]!=a[x]){
                ans[a[x]]=x-i;
                break;
            }
        }
        for(int i=1;i<=2;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }else{
        x=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[i-1]&&i!=1){
                cout<<x<<" ";
            }
            x++;
        }
        cout<<x<<endl;
    }
}
