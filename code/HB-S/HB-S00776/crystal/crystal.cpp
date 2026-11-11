#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500010];

int sqr(int n){
    int l=1,r=n;
    while(l>r){
        int m=l+(r-l)/2;
        if(m*m==n) return m;
        if(m*m>n){
            r=m;
        }else{
            l=m+1;
        }
    }
    return l-1;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    bool t100=1,ta=1,d=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(abs(a[i])>100){
            ta=0;
        }
        if(i==2){
            d=a[2]-a[1];
        }
        if(i>2&&a[i]-a[i-1]!=d){
            ta=0;
        }
    }
    sort(a+1,a+n+1);
    if(n<=5000){//1-9
        int sum=0;
        for(int i=2;i<=n;i++){
            int s=m,cnt=1;
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]<=s){
                    cnt++;
                    s-=a[i]-a[j];
                }else{
                    break;
                }
            }
            sum=max(sum,cnt);
        }
        cout<<sum;
    }else if(t100){//10-12
        int cnt[250]={};
        for(int i=1;i<=n;i++){
            cnt[a[i]+100]++;
        }
        int sum=0;
        for(int i=0;i<=200;i++){
            int s=m,cn=0;
            if(cnt[i]==0) continue;
            for(int j=i;j>=0;j--){
                if(cnt[j]==0) continue;
                if(cnt[j]*(i-j)<=s){
                    s-=cnt[j]*(i-j);
                    cn+=cnt[j];
                }else if(i-j<=s){
                    while(s>=i-j){
                        cn++;
                        s-=i-j;
                    }
                    break;
                }else{
                    break;
                }
            }
            sum=max(sum,cn);
        }
        cout<<sum;
    }else if(ta&&d==1){//13-15
        cout<<min(n,sqr(m*2));
    }else if(ta){//16-18
        int l=1,r=n;
        while(l<r){
            int mr=l+(r-l)/2;
            if((a[1]+a[mr])*((a[mr]-a[1])/d+1)/2==m){
                cout<<mr;
                return 0;
            }else if((a[1]+a[mr])*((a[mr]-a[1])/d+1)/2>m){
                r=m;
            }else{
                l=m+1;
            }
        }
        cout<<l-1;
    }//1-18 60-90pts
    return 0;
}
