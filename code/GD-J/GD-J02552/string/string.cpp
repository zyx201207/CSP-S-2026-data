#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
long long sum,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
        sum+=a[i];
    }
    long long mid = sum/2;
    if(sum&1)mid++;
    int t = 1;
    for(int i=1;i<=n;i++){
        if(s[i+1]!=s[i]){
            t=0;
            break;
        }
    }
    if(t){
        cout<<0;
        return 0;
    }
    long long cnt1=0,cnt2=0,sum1=0,sum2=0;
    int t1=1;
    int t2 = 1;
    for(int i=1,j=n;i<=j;){
        if(t1){cnt1+=a[i];sum1+=a[i];}
        if(t2){cnt2+=a[j];sum2+=a[j];}
        if(sum1>=mid&&sum&1)cnt1--;
        if(sum2>=mid&&sum&1)cnt2--;
        t1=0;
        t2=0;
        if(s[i]!=s[j]){
            ans+=min(cnt1,cnt2);
        }
        if(cnt2>cnt1){
            cnt2-=cnt1;
            t1=1;
            i++;
        }
        else if(cnt1>cnt2){
            cnt1-=cnt2;
            t2=1;
            j--;
        }
        else{
            cnt1=0;
            t1=1;
            t2=1;
            cnt2=0;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
