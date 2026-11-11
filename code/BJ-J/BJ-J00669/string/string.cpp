#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,cnt,m[N],mm;
char p[N],pp,a[N/2],b[N/2];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    long long sum=0,jj=0;
    for(int i=1;i<=n;i++){
        cin>>mm>>pp;
        sum+=mm;
        for(long long ii=1;ii<=mm;ii++){
            jj++;
            p[jj]=pp;
        }
    }
    if(sum%2==0){
        for(long long i=1;i<=sum/2;i++){
            a[i]=p[i];
        }
        int j=0;
        for(long long i=sum;i>=sum/2+1;i--){
            j++;
            b[j]=p[i];
        }
        for(long long i=1;i<=sum/2;i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        cout<<cnt;
    }else{
        for(long long i=1;i<=sum/2;i++){
            a[i]=p[i];
        }
        long long j=0;
        for(long long i=sum;i>=sum/2+2;i--){
            j++;
            b[j]=p[i];
        }
        for(long long i=1;i<=sum/2;i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}