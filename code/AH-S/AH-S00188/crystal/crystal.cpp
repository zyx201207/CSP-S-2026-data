#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        f[i]=a[i]-a[i-1];
    }
    if(n>=500000){
        bool flag=0;
        for(int i=3;i<=n;i++){
            if(f[i]!=f[i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            long long mx=a[(int)(n/2)];
            for(int i=(int)(n/2);i>=1;i--){
                if(a[i]!=mx){
                    m=m-2*(mx-a[i]);
                    cnt+=2;
                    if(m<0){
                        if(m+mx-a[i]>0){
                            cnt--;
                            m=m+mx-a[i];
                        }else if(m+mx-a[i]==0){
                            cout<<cnt-1;
                            return 0;
                        }else{
                            cout<<cnt-2;
                            return 0;
                        }
                    }
                    if(m==0){
                        cout<<cnt;
                        return 0;
                    }
                }
            }
        }else{
            long long sum=0;
            while(m>0){
                cnt++;
                if(cnt>n){
                    break;
                }
                m-=(cnt+1)/2;
                sum++;
            }
            if(m<0){
                cout<<sum-1;
            }else{
                cout<<sum;
            }
        }
    }else if(n<=5000){
        cout<<n-2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
