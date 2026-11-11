#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cnt[500005],a[500005];
bool flag;
vector<long long> ve;
void aaa(long long x){
    for(long long i=x;i<=n;i++){
        for(long long j=0;j<ve.size();j++){
            if(ve[j]==a[i]){
                flag=1;
            }
        }
        if(flag){

            ve.clear();
            flag=0;
        }
        ve.push_back(a[i]);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        ve.clear();
        flag=0;
        aaa(i);
        for(long long j=0;j<ve.size();j++){
            cnt[ve[j]]++;
        }
    }

    for(long long i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
