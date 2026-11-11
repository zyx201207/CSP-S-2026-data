#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,mid,ans=1;
bool  check(long long x){
    long long cnt=0,cnt2=0,ls2=0;
    bool flag=0;
    set<pair<long long,long long>>st;
    vector<long long>v;
    for(int i=0;i<n;i++){
        if(a[i]<=x){
            st.insert({x-a[i],i});
            //cout<<'i'<<i<<endl;
            cnt2++;
            cnt+=x-a[i];
        }else break;
    }//cout<<"cnt11 "<<cnt<<endl<<"cnt21 "<<cnt2<<endl;
    while(cnt>m){
            auto it1=st.end();
            it1--;
            auto it=*it1;
        cnt-=it.first;
        st.erase(it1);
        cnt2--;
        //cout<<cnt2<<'p'<<cnt<<endl;
    }//cout<<"cnt12 "<<cnt<<endl<<"cnt22 "<<cnt2<<endl;
    for(auto x:st)v.push_back(x.second);
    long long len=v.size();
    for(long long i=0;i<len;i++){
        if(v[i]<=(n-1)/2)ls2++;
    }
    if(cnt2>ans){
        ans=cnt2;
        if(ls2<len-ls2)return 1;
        else return 0;
    }else {
        if(ls2<len-ls2)return 0;
        else return 1;
    }

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    r=a[n-1];
    l=a[0];
    while(l<=r){
        mid=(l+r)/2;
        //cout<<mid<<"\n";
        if(check(mid))l=mid+1;
        else r=mid-1;

    }cout<<ans;
    return 0;
}
/*
5 5
2 2 4 5 9

5 8
-3 -1 2 2 7
*/
