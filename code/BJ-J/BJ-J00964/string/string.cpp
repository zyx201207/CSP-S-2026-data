#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],b[3*N];
char c[N],d[3*N];
long long n,m,ans;
vector<long long>e;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    e.push_back(0);
    e.push_back(0);
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        e.push_back(sum);
    }
    sum=0;
    for(int i=n;i>=1;i--){
        sum+=a[i];
        e.push_back(sum);
    }
    sort(e.begin(),e.end());
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        while(m<e.size()-1&&sum>=e[m+1]){
            d[++m]=c[i];
            b[m]=e[m]-e[m-1];
        }
    }
    int l=1,r=m;
    while(l<r){
        //<<b[l]<<endl;
        //if(b[l]!=b[r])cout<<"!"<<endl;
        if(d[l]!=d[r])ans+=b[l];
        l++,r--;
    }
    cout<<ans<<endl;
    return 0;
}



