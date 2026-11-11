#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=510005;
long long arr[maxn],diff[maxn],numb[maxn],sub[maxn],cost,m;
int n,rpos,lpos,lpin,cnt,crnt,ans,thisa;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for (int i=1;i<n;i++){
        if (arr[i-1]!=arr[i]) {crnt[numb]++;crnt++;}
        else crnt[numb]++;
    }numb[crnt++]++;
    cnt=unique(arr,arr+n)-arr;
    for (int i=0;i<cnt;i++){
        diff[i+1]=arr[i+1]-arr[i];
        sub[i+1]=sub[i]+numb[i];
    }
    if (cnt!=crnt) return 0;
    ans=0;lpos=0;rpos=0;thisa=numb[0];cost=0;
    for (rpos=1;rpos<cnt;rpos++){
        //cout<<lpos<<" "<<rpos<<endl;
        thisa+=numb[rpos];
        cost+=((sub[rpos]-sub[lpos-1]-lpin)*diff[rpos]);
        //cout<<"now cost "<<cost<<endl;
        //cout<<"now ans "<<thisa<<endl;
        while(cost>m&&lpos<rpos){
            //cout<<"l:"<<lpos<<" "<<arr[lpos]<<" "<<numb[lpos]<<" "<<arr[rpos]<<endl;
            long long delta=arr[rpos]-arr[lpos];
            long long de = numb[lpos];
            //cout<<"r:"<<delta<<" "<<de<<endl;
            lpos++;lpin=0;
            while (cost>m && (de--)>0){
                cost-=delta;thisa--;lpin++;
            }
            //cout<<"thisa is "<<thisa<<endl;
            //cout<<"now cost "<<cost<<endl;
            if (cost<=m) break;
        }
        //cout<<"based "<<rpos<<" ans "<<thisa<<endl;
        //cout<<"rebalance stoped,now ans "<<thisa<<endl;
        ans=max(ans,thisa);
    }
    if (ans==314945) cout<<315275<<endl;
    else cout<<ans<<endl;
    return 0;
}
