#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
bool book[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);/*zhushi!!!!!!!!!!!!!!!!!!!*/
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    vector<long long>v;
    for(int mask=31;mask>=0;mask--){
        v.clear();
        bool flag=0;
        long long id=0,num=0;
        for(int i=1;i<=n;i++){
            if(book[i])continue;
            if((1ll<<mask)&a[i]){
                num++;
            }else v.push_back(i);
        }
        if(num>=m){
                //cout<<(1<<mask)<<endl;
            ans|=(1<<mask);
            for(int i=0;i<(long long)v.size();i++){
                book[v[i]]=1;
            }
        }

    }
    cout<<ans;
    return 0;
}
