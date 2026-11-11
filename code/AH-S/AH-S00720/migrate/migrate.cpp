#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long f[1000010];
long long b[1000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        f[1]=0;
        long long pos=1,c=1;
        for(int i=2;i<=n;i++){
            if(a[i]<=a[pos]+d) f[i]=c;
            else{
                pos=i-1;
                c++;
                f[i]=c;
            }
            if(a[i]-a[i-1]>d){
                pos=i;
                c=1;
                f[i]=0;
            }
        }
        int cnt=0;
        for(int i=4;i<=n;i++){
            if(f[i]==f[i-3]+2&&f[i]==f[i-2]+1&&f[i-1]+1==f[i]||f[i]==f[i-1]&&f[i-2]==f[i-3]&&f[i-3]==f[i]-1) cnt++;
        }
        cout<<cnt<<endl;
    }
}
