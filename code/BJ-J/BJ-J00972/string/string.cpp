#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    char s;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    deque<node> dp;
    cin>>n;
    vector<node> a;
    long long sum=0;
    for(int i=0;i<n;i++){
        long long b;
        char c;
        cin>>b>>c;
        sum+=b;
        a.push_back({b,c});
    }
    long long nsum=0;
    int j;
    long long all=0;
    for(int i=0;i<n;i++){
        node now=a[i];
        if(nsum+now.num>=(sum+1)/2){
            if(sum/2-nsum) dp.push_back({sum/2-nsum,now.s});
            a[i].num-=(sum/2-nsum);
            nsum+=(sum/2-nsum);
            if(sum%2) a[i].num--;
            j=i;
            //if(!a[i].num) j++;
            break;
        }
        dp.push_back(now);
        nsum+=now.num;
    }
    long long ans=0;
    for(int i=j;i<n;i++){
        if(a[i].s!=dp.back().s){
            ans+=min(a[i].num,dp.back().num);
        }
        //all+=min(a[i].num,dp.back().num);
        long long nnn=a[i].num;
        a[i].num-=min(a[i].num,dp.back().num);
        dp.back().num-=min(nnn,dp.back().num);
        if(!dp.back().num){
            dp.pop_back();
        }
        if(a[i].num) i--;
    }
    cout<<ans;
    return 0;
}
