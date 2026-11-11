#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],s[N];
long long sum,minn=LONG_MAX,m;
unsigned long long t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    for(int i=1;i<=n;i++){
        if(abs(sum-a[i])<minn){
            minn=abs(sum-a[i]);
            m=i;
        }
    }
    for(int i=1;i<=n;i++){
        s[i]=(abs(a[m]-a[i]));
    }
    sort(s+1,s+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]<=t){
            cnt++;
            t-=s[i];
        }
    }
    cout<<cnt<<endl;
}
