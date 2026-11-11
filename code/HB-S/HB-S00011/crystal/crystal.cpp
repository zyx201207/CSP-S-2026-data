#include<bits/stdc++.h>
using namespace std;
long long  a[500005];
long long sum[500005];

long long  l,r;
long long  ans,now;
bool flagi=true;
bool flagg=true;
long long c;
long long  n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    long long  q=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+i-1;

        if(a[i]!=i){
            flagi=false;
        }
        if(i==2){
            c=a[i]-a[1];
        }
        if(i>=2){
            if((a[i]-a[i-1])!=c){
                flagg=false;
            }
        }
    }
    if(flagi){
        int pos=1;
        while(1){
            long long t=sum[pos];
            if(t<=m){
                ans=pos;
                pos++;
                if(pos>n){
                    break;
                }

            }else {
                break;
            }
        }
        cout<<ans;

        return 0;
    }
    if(flagg){
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+i*c-c;
        }
        int pos=1;
        while(1){
            long long t=sum[pos];
            if(t<=m){
                ans=pos;
                pos++;
                if(pos>n){
                    break;
                }
            }else {
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
            now=0;
            if(a[i]==a[i+1]){
                continue;
            }
        q=m;
        int p=i;
        while(1){
            long long  t=abs(a[i]-a[p]);
            if(q<t||p<1){
                break;
            }
            q-=t;
            p--;
            now++;
        }
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}
