#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t,n,d,a[N],b[N][N];
int main() {
    cin>>c>>t;
    while(t--) {
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                b[i][j]=0;
            }
        }
        cin>>n>>d;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(a[j]-a[i]<d) break;
                else 
                    b[i][j]++;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                for(int k=j+1;k<=n;k++) {
                    b[i][k]=b[i][j]+b[j][k];
                }
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(b[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}