#include<iostream>

using namespace std;

const long long MAXN=2e6+10;
long long x[MAXN],l[MAXN],cnt[MAXN];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;

    if(0){

    }else{
        while(t--){
            long long n,d,ans=0;
            cin>>n>>d;
            for(long long i=0;i<n;i++){
                cin>>x[i];
            }
            for(long long s=0;s<n;s++){
                for(long long k=s;k<n;k++)cnt[k]=0;
                long long i=s+1,j=s;
                l[s]=0;
                cnt[s]=1;
                while(i<n&&x[i]-x[s]<=d){
                    l[i]=1;
                    cnt[i]=1;
                    i++;
                }
                while(i<n){
                    while(x[i]-x[j]>d)j++;
                    if(cnt[j]==0)break;
                    l[i]=l[j]+1;
                    for(long long k=j;k<i&&l[k]==l[j];k++){
                        cnt[i]+=cnt[k];
                    }
                    if(cnt[i]>2)break;
                    else if(cnt[i]==2)ans++;
                    i++;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
