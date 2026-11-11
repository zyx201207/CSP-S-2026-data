#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=(1<<31)-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    int ans=0;
    sort(a.begin(),a.end());
    vector<int> p(m);
    for(int i=0;i<m;++i)
        p[i]=i;
    while(p[0]<=n-m){
        int cur=INF;
        for(int i=0;i<m;i++)
            cur=cur & a[p[i]];
        ans=max(ans,cur);
        for(int i=0;i<m;i++)
            cout<<a[p[i]]<<' ';
        cout<<" cur: "<<cur<<endl;
        p[m-1]++;
        int ptr=m;
        for(int i=m-1;i>0;i--){
            if(p[i]-i>n-m)
                ptr=i,
                p[i-1]++;
        }
        for(int i=ptr;i<m;i++)
            p[i]=p[i-1]+1;
    }
    cout<<ans;
    return 0;
}
