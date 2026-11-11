#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],ans,total,cnt,cnt2,now,now_cnt2;
bool f;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        total+=a[i];
    }
    now=n;
    for(int i=1;i<=n;i++){
        cnt+=a[i];
        char same=c[i];
        if(cnt>=total/2){
            cnt=total/2;
            cnt2+=(a[now]-now_cnt2);
            if(cnt2>=cnt){
                cnt2-=(a[now]-now_cnt2);
                now_cnt2+=(cnt-cnt2);
                if(c[now]!=same) ans+=(cnt-cnt2);
                cnt2=cnt;
                break;
            }
            if(c[now]!=same) ans+=(a[now]-now_cnt2);
            for(int j=now-1;j>=1;j--){
                cnt2+=a[j];
                if(cnt2>=cnt){
                    cnt2-=a[j];
                    if(c[j]!=same) ans+=cnt-cnt2;
                    break;
                }else{
                    if(c[j]!=same) ans+=a[j];
                }
            }
            break;
        }else{
            cnt2+=(a[now]-now_cnt2);
            if(cnt2>=cnt){
                cnt2-=(a[now]-now_cnt2);
                now_cnt2+=(cnt-cnt2);
                if(c[now]!=same) ans+=(cnt-cnt2);
                cnt2=cnt;
            }else{
                if(c[now]!=same) ans+=(a[now]-now_cnt2);
                for(int j=now-1;j>=1;j--){
                    cnt2+=a[j];
                    if(cnt2>=cnt){
                        cnt2-=a[j];
                        now=j;
                        now_cnt2=cnt-cnt2;
                        cnt2=cnt;
                        if(c[j]!=same) ans+=now_cnt2;
                        break;
                    }else{
                        if(c[j]!=same) ans+=a[j];
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
