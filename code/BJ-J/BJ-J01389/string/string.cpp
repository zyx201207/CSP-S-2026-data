#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200009];
char b[200009];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
    }
    int ans=0;
    int cnt=a[1],cnt2=a[n];
    int sum1=a[1],sum2=a[n];
    for(int i=1,j=n;i<j;){
        if(b[i]==b[j]){
            if(cnt>cnt2){
                cnt-=cnt2;
                j--;
                sum2+=a[j];
                cnt2=a[j];
            }else if(cnt<cnt2){
                cnt2-=cnt;
                i++;
                sum1+=a[i];
                cnt=a[i];
            }else{
                i++,j--;
                cnt=a[i];
                cnt2=a[j];
                sum1+=a[i];
                sum2+=a[j];
            }
        }else{
            if(cnt>cnt2){
                ans+=cnt2;
                cnt-=cnt2;
                j--;
                sum2+=a[j];
                cnt2=a[j];
            }else if(cnt<cnt2){
                ans+=cnt;
                cnt2-=cnt;
                i++;
                sum1+=a[i];
                cnt=a[i];
            }else{
                ans+=cnt;
                i++,j--;
                cnt=a[i];
                cnt2=a[j];
                sum1+=a[i];
                sum2+=a[j];
            }
        }
    }
    cout<<ans;
    return 0;
}