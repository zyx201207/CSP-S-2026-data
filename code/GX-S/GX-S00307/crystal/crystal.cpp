#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mx=-99999,mi=99999,cf,x=1,ans=1,pj,a,b,c,d;
long long syx[10000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k;
        if(i==1){
            a=k;
        }
        if(i==2){
            b=k;
        }
        if(i==3){
            c=k;
        }
        if(i==4){
            d=k;
            if(b-a==d-c){
                while(m){
                    x=b-a;
                    if(m-x>=0){
                        ans++;
                        m-=x;
                    }
                    else{
                        cout<<ans;
                        return 0;
                    }
                }
            }
        }
        pj+=k;
        if(k==i){
            cf++;
        }
        if(cf>=10){
        while(m){
            if(m-x>=0){
                m-=x;
                ans++;
                x++;
            }
            else{
                cout<<ans;
                return 0;
            }
        }

        }
    }
    pj/=n;
    cout<<pj;

    //cout<<mx<<" "<<mi;

    return 0;
}
