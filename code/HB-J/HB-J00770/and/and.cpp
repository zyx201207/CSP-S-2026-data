#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N][31],t[N][31],ans[31];
int n,m;
void work(int w){
    while(w!=0){
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i][w]==1){
                flag++;
            }
        }
        if(flag<m){w--;continue;}
        ans[w]=1;
        int nn=0;
        for(int i=1;i<=n;i++){
            if(a[i][w]==1){
                nn++;
                for(int j=1;j<=30;j++){
                    t[nn][j]=a[i][j];
                }
            }
        }
        n=nn;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=30;j++){
                a[i][j]=t[i][j];
            }
        }
        w--;
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=30;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        */
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        int w=0;
        while(x!=0){
            a[i][++w]=x%2;
            x/=2;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    work(30);
    long long sum=0;
    for(int i=30;i>=1;i--){
        if(ans[i]==1)sum=sum+pow(2,i-1);
      //  cout<<ans[i];
    }
    cout<<sum;
    return 0;
}
