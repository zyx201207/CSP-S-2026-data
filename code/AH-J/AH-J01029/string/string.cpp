#include<bits/stdc++.h>
using namespace std;
long long n;
struct piece{
    char c;
    long long  tms;
}ps[200005],reps[200005];
long long sum[200005],resum[200005];
set<long long> st;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>ps[i].tms>>ps[i].c;
        reps[n-i+1]=ps[i];
    }
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+ps[i].tms;
        resum[i]=resum[i-1]+reps[i].tms;
        st.insert(sum[i]);
        st.insert(resum[i]);
    }
    long long len=st.size();
    long long i=1,j=1,last=0,ans=0;
    for(long long it:st){
        while(it>sum[i])i++;
        while(it>resum[j])j++;
        if(ps[i].c!=reps[j].c)ans+=it-last;
        last=it;
    }
    cout<<ans/2<<endl;
    return 0;
}
