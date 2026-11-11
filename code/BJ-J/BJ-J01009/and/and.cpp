#include<bits/stdc++.h>
using namespace std;
int a[200010];
int mm[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int pa=1;
    int pb=1;
    int pc=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((int)(log2(a[i]+1))!=(log2(a[i]+1))){
            pa=0;
        }
        if(a[i]!=i-1){
            pb=0;
        }
    }
    if(n<=27){
        int ans=0;
        for(int i=0;i<=(1<<n);i++){
            int nn=i;
            int ci=0;
            int cnt=0;
            while(nn>0){
                ci++;
                if(nn%2==1){
                    mm[ci]=1;
                    cnt++;
                }
                else{
                    mm[ci]=0;
                }
                nn/=2;
            }
            if(cnt==m){
                int now=(1<<31)-1;
                for(int j=1;j<=n;j++){
                    if(mm[j]==1){
                        now=now&a[j];
                    }
                }
                ans=max(ans,now);
            }
        }
        cout<<ans;
    }
    else if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        if(ans>3){
            pc=0;
        }
        cout<<ans;
    }
    else if(m==n){
        int ans=(1<<31)-1;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        int ans=0;
        for(int i=1;i<=n;i++){
            int lin=(1<<31)-1;
            for(int j=1;j<=n;j++){
                if(j!=i)lin=lin&a[j];
                if(lin==0) break;
            }
            ans=max(ans,lin);
        }
        cout<<ans;
    }
    else if(pa==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=min(ans,a[i]);
        }
        cout<<ans;
    }
    else if(pb==1){
        int ans=0;
        int wei=log2(n)+1;
        int l=1,r=1;
        while((1<<(l-1)*(1<<(wei-r)))<m){
            r++;
            l++;
        }
        while((1<<(l-1)*(1<<(wei-r)))>m){
            r++;
        }
        for(int i=l-1;i<=r-2;i++){
            ans+=(1<<i);
        }
        cout<<ans;
    }
    else if(pc==1){
        int n1=0,n3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) n1++;
            if(a[i]==3) n3++;
        }
        if(n3>=m) cout<<3;
        else if(n3+n1>=m) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
