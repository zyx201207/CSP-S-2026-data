#include<bits/stdc++.h>
using namespace std;
int n,a[200005],pre[200005],suf[200005],m;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int now=(1<<30)-1;
            int cnt=0,tmp=i;
            while(tmp){
                cnt+=(tmp&1);
                tmp>>=1;
            }
            if(cnt!=m) continue;
            for(int j=1;j<=n;j++){
                if(i&(1<<j-1)){
                    now&=a[j];
                }
            }
            ans=max(ans,now);
        }
        cout<<ans;
        return 0;
    }else if(n<=2000){
        if(m==1){
            cout<<*max_element(a+1,a+1+n);
            return 0;
        }else if(m==2){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
            return 0;
        }else if(m==n){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans&=a[i];
            }
            cout<<ans;
            return 0;
        }
    }else{
        if(m==n-1){
            pre[0]=suf[n+1]=(1<<30)-1;
            for(int i=1;i<=n;i++) pre[i]=pre[i-1]&a[i];
            for(int i=n;i>=1;i--) suf[i]=suf[i+1]&a[i];
            int ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,pre[i-1]&suf[i+1]);
            }
            cout<<ans;
            return 0;
        }
        bool fl1=1,fl2=1,fl3=1;
        for(int i=1;i<=n;i++){
            fl1&=(a[i]==i-1);
            int len=0,cnt=0,tmp=a[i];
            while(tmp){
                len++;
                cnt+=(tmp&1);
                tmp>>=1;
            }
            fl2&=(len==cnt);
            fl3&=(a[i]<=4);
        }
        if(fl1){
            cout<<a[n-m+1];
            return 0;
        }
        if(fl2){
            sort(a+1,a+1+n,greater<int>());
            cout<<a[m];
            return 0;
        }
        if(fl3){
            int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt0=0;
            for(int i=1;i<=n;i++){
                cnt1+=(a[i]==1);
                cnt2+=(a[i]==2);
                cnt3+=(a[i]==3);
                cnt4+=(a[i]==4);
                cnt0+=(!a[i]);
            }
            if(cnt4>=m) cout<<4;
            else if(cnt3>=m) cout<<3;
            else if(cnt3+cnt2>=m||cnt2>=m) cout<<2;
            else if(cnt3+cnt1>=m||cnt1>=m) cout<<1;
            else cout<<0;
            return 0;
        }
    }
    return 0;
}
//CCF,I want CSP-J 300pts,please! CSP-S 150+pts,please!
