#include<bits/stdc++.h>
using namespace std;
int c,t,n,as,ae,bs,be;
long long d,x[2000001],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==11||c==12){
            int dx=x[2]-x[1];
            if(dx*2>d)cout<<0<<endl;
            else if(dx*3<=d)cout<<0<<endl;
            else cout<<n-3<<endl;
            continue;
        }
        as=1,ae=0,bs=0,be=0;
        if(x[2]-x[1]>d)as=2;
        if(x[3]-x[2]>d)as=3;
        for(int i=4;i<=n;i++){
            if(x[i]-x[i-1]>d&&x[i]-x[i-3]<=d){
                as=bs-2;
                ae=be-2;
                bs=be+1;
                be=i-1;
                ans+=max(ae-as+1,0)*max(be-bs+1,0);
                as=i;
                continue;
            }
            if(x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d){
                    if(ae==0){
                        ae=i-3;
                        bs=i;
                    }else if(be==0){
                        be=i-1;
                    }else{
                        as=bs-2;
                        ae=be-2;
                        bs=be+1;
                        be=i-1;
                    }
                    ans+=max(ae-as+1,0)*max(be-bs+1,0);
            }
            //cout<<as<<' '<<ae<<' '<<bs<<' '<<be<<endl;
        }
        if(be!=n-1){
            if(ae==0){
                ae=n-3;
                bs=n;
            }else if(be==0){
                be=n-1;
            }else{
                as=bs-2;
                ae=be-2;
                bs=be+1;
                be=n-1;
            }
            //cout<<as<<' '<<ae<<' '<<bs<<' '<<be<<endl;
            ans+=max(ae-as+1,0)*max(be-bs+1,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
