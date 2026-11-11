#include<bits/stdc++.h>
using namespace std;
long long n,m,last,ut=0,ans,k;
long long x[500050],a[500050],s[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }//for(int i=1;i<=n;i++)x[i]+=10;

    sort(x+1,x+n+1);
    if(n<=5000){
        for(int i=2;i<=n;i++){
            a[i]=x[i]-x[i-1];
        }
        ut=x[n];
        for(int i=n;i>=1;i--){
            s[i]+=s[i+1]+ut-x[i];
        }
        //for(int i=1;i<=n;i++)cout<<x[i]<<" ";
        //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        //for(int i=1;i<=n;i++)cout<<s[i]<<" ";
        //cout<<endl;
        for(long long i=n;i>=1;i--){
            long long l=1,r=i,mid;
            //m+=(n-i)*a[i+1];
            k+=a[i+1];
            while(l<r){
                mid=(l+r)/2;
                //cout<<s[mid]<<" "<<l<<" "<<r<<endl;
                //cout<<mid<<" ";
                if(m>s[mid]-(n-mid-1)*a[i+1]-k){
                    r=mid;
                }else if(m==s[mid]-(n-mid-1)*a[i+1]-k){
                    l=r=mid;break;
                }else{
                    l=mid+1;
                }
            }
            //cout<<r<<endl;
            ans=max(ans,i-l+1);
            //cout<<endl;
        }
        cout<<ans;
    }else{
        int l=x[2]-x[1],sum=0,ss=0;
        for(int i=1;i<=n;i++){
            sum+=l;
            ss+=sum;
            if(m<ss){
                cout<<i;return 0;
            }
        }
        cout<<n;
    }
    return 0;
}
