#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int arr[N],n,m,w[N],dp[N],l=1,ans,len,ww,v,tw;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    //w[1]=arr[1];

    for(int i=2;i<=n;i++)w[i]=arr[i]-arr[i-1];
    //for(int i=1;i<=n;i++)cout<<w[i]<<" ";
    //cout<<endl;

    for(int i=1;i<=n;i++){
        tw=w[i]*(i-l);
        //cout<<tw<<" ";
        if(m>=tw+ww){
            ww+=tw;
            len++;
            ans=max(ans,len);
        }

        else if(m<w[i]){
            ww=w[i+1]-w[i];
            l=i;
            len=1;
        }
        else{//important
            while(m<tw+ww){
                ww-=(arr[i]-arr[l]);
                l++;
                tw=w[i]*(i-l);
                //cout<<tw<<endl;

                len--;
                if(len<0 or l>=i){
                    ww=w[i+1]-w[i];
                    l=i;
                    len=1;
                    break;
                }
            }
            len++;
            ans=max(ans,len);
        }
        //cout<<len<<endl;
    }
    cout<<ans;

    return 0;
}

