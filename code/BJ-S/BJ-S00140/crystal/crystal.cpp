#include <iostream>
using namespace std;
long long int jdz(long long int a,long long int b){
    return max(a-b,b-a);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long int n;
    long long int m;
    cin>>n>>m;
    long long int a[500005];
    for(long long int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m>100000000){
        int ans=0,cha=jdz(a[1],a[2]);
        while(m>=0){
            ans++;
            m-=cha*ans;
        }
        if(ans-1>0)cout<<ans;
        else cout<<0;
        return 0;
    }
    else{
        //long long int num[500005],ans=0   ,sum=0,big=-1000000000005;

        /*for(long long int i=1;i<=n-1;i++){
            for(long long int j=i+1;j<=n;j++){
                long long int cha=jdz(a[i],a[j]);

                if(cha+sum<=m){
                    ++ans;
                    sum+=cha;
                    if(cha>big)big=cha;
                }

                else{

                    if(cha<big){
                        sum=sum-big+cha;
                        big=cha;
                        for(long long int i=1;i<=ans;i++){
                            if(num[i]>big)big=num[i];
                        }
                    }
                }
            }
        }*/

        //if(ans>0)cout<<ans+1;
        //else cout<<0;
        for(long long int i=1;i<=n;i++){
            for(long long int j=1;j<=i;j++){
                if(a[j]>a[i])swap(a[j],a[i]);
            }
        }
        /*int sam=0;
        for(long long int i=1;i-1<=n;i++){
            if(a[i]==a[i+1])++sam;
        }*/
        int step=0;
        for(long long i=1;i<=n-1;i++){
            int cha=jdz(a[i],a[i+1]);
            if(m>=0){
                step++;
                m-=step*cha;
            }
        }
        if(step-1>0)cout<<step;
        else cout<<0;
        return 0;
    }
    return 0;
}
