#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12){
            if(d<2*(x[2]-x[1])) cout<<0<<endl;
            else{
               long long p=2*d/(x[2]-x[1]);
                if(n-p+1>=0) cout<<n-p+1<<endl;
                else cout<<0<<endl;
            }
        }else if(c>=1&&c<=10){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]>d){
                        long long t=(x[j]-x[i])/d;
                        long long p=lower_bound(x+i+1,x+j+1,x[j]-d)-x,q=upper_bound(x+i+1,x+j+1,x[i]+d)-x,s=0;
                        s=q-p;
                        //if((j-i)%2==0&&(i+j)/2>=p) s--;
                        if(s==2) ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }else cout<<0<<endl;
    }
    return 0;
}
