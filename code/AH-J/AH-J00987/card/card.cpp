#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
unordered_map<int,int>idx,cnt;
int main(){
    //reopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>n>>m;
    a.reserve(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    size_t idx_v=0;
    for(size_t i=1;i<=n;i++){
        deque<int>x;
        for(int j=i;j<=n;j++){
            bool f=0;
            for(int num:x)
                if(num==a[j]){
                    f=1;break;
                }
            cnt[a[j]]+=f;
        }
    }
    for(int i=1;i<m;i++)
        cout<<cnt[i]<<' ';
    cout<<(cnt.count(m)?cnt[m]:0);
    //fclose(stdin);fclose(stdout);
    return 0;
}
