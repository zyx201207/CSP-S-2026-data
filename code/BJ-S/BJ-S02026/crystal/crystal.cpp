#include <bits/stdc++.h>
using namespace std;
long long n,mm,m,ans=1,anss,k;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>mm;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    m=mm;
    k=1;
    for(long long i=2;i<=n;i++){
        if(m>=(a[i]-a[i-1])*(i-k)){
            m-=(a[i]-a[i-1])*(i-k);
            ans++;
            anss=max(anss,ans);
        }else{
            long long ml=m;
            bool flag=0;
            for(k;k<=i;k++){
                ml+=a[i-1]-a[k];
                ans--;
                if(ml>=(a[i]-a[i-1])*(i-k)){
                    m=ml-(a[i]-a[i-1])*(i-k);
                    ans++;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                k=i;
                ans=1;
                m=mm;
            }
        }
    }
    anss=max(anss,ans);
    cout<<anss<<endl;
    return 0;
}