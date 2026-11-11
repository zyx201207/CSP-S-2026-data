#include<bits/stdc++.h>

using namespace std;
const int maxn=5e5+10;
long long n,m,a[maxn];
int b[5010][5010],ans=0;
bool ta=true,tb=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i+1)ta=false;
    }
    sort(a,a+n);
    long long mina=a[0],maxa=a[n-1];
    long long d=a[1]-a[0];
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=d)tb=false;
    }
    if(n<=5000){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                b[i][j]=a[i]-a[j];
            }
        }
        for(int i=1;i<n;i++){
            int cost=0,cnt=0;
            for(int j=i-1;j>=0;j--){
                cnt++;
                cost+=b[i][j];
                if(cost==m){
                    break;
                }
                if(cost>m){
                    cnt--;
                    break;
                }
            }
            ans=max(ans,cnt+1);
        }
        cout<<ans<<'\n';
    }else{
        if(ta){
            for(int i=0;i<n;i++){
                ans++;
                m-=i;
                if(m<0){
                    ans--;
                    break;
                }
                if(m==0)break;
            }
            cout<<ans<<'\n';
        }else if(tb){
            for(int i=0;i<n;i++){
                ans++;
                m-=d*i;
                if(m<0){
                    ans--;
                    break;
                }
                if(m==0)break;
            }
            cout<<ans<<'\n';
        }else{
            for(int i=mina+1;i<=maxa;i++){
                int cnt=0,tmp=m;
                for(int j=n-1;j>=0;j--){
                    if(a[j]<=i){
                        cnt++;
                        tmp-=(i-a[j]);
                        if(tmp<0){
                            cnt--;
                            break;
                        }
                        if(tmp==0)break;
                    }
                }
                ans=max(ans,cnt);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
