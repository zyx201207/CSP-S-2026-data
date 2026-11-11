#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long val[N];
char c[N];
long long sum[30];
long long res=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>val[i]>>c[i];
        sum[c[i]-'a']+=val[i];
        res+=val[i];
    }
    long long ans=0;
    int l=1,r=n;
    while(l<=r){
        while(l<=r&&val[l]==0){
            l++;
        }
        while(l<=r&&val[r]==0){
            r--;
        }
        if(l>r){
            break;
        }
        if(c[l]!=c[r]){
            if(val[l]!=val[r]){
                ans+=max(val[l],val[r]);
                val[r-1]-=abs(val[l]-val[r]);
                if(val[r-1]<0){
                    val[l+1]-=0-val[r-1];
                    val[r-1]=0;
                }
            }else{
                ans+=val[l];
            }
        }else{
            if(val[l]!=val[r]){
                ans+=max(val[l],val[r]);
                val[r-1]-=abs(val[l]-val[r]);
                if(val[r-1]<0){
                    val[l+1]-=0-val[r-1];
                    val[r-1]=0;
                }
            }
        }
        l++,r--;
    }
    sort(sum,sum+25,greater<long long>());
    if(res-sum[0]<ans){
        cout<<res-sum[0]<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
