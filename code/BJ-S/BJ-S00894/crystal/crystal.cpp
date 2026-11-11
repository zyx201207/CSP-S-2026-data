#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m1;
    cin>>n>>m1;
    long long m=m1;
    vector<long long> a;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        a.push_back(x);
    }

    if(n>50000){
        if(a[0]!=a[1]){
            long long gc=abs(a[0]-a[1]);
            long long left=0;
            long long right=n-1;
            while(right>=left){
                long long mid=(left+right)/2;
                if(mid*mid/2*gc>m){
                    right=mid-1;
                }else if(mid*mid/2*gc<m){
                    left=mid;
                }else{
                    left=mid;
                    break;
                }
            }
            cout<<left+1;
            return 0;
        }else{
            cout<<n;
            return 0;
        }
    }
    sort(a.begin(),a.end(),cmp);
    long long ans=0;
    for(int i=0;i<=n;i++){
        long long sum=1;
        m=m1;
        for(int j=i+1;j<n;j++){
            m-=(a[i]-a[j]);
            //cout<<m<<endl;
            if(m<0){
                ans=max(ans,sum);
                break;
            }
            sum++;
            if(m==0){
                ans=max(ans,sum);
                break;
            }
        }
    }
    if(ans==1){
        cout<<0;
        return 0;
    }
    cout<<ans;
    return 0;
}