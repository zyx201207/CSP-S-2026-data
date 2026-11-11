#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,m;
unsigned long long a[maxn];
bool cmp(long long a,long long b){return a<b;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    unsigned long long ans=m,cnt=0;
    for(int i=1;i<=n;i++){
        ans=ans+a[i];
        cnt+=(ans/i);
    }
    long long maxx=0;
    for(int i=n;i>=1;i--){
        if(a[i]>ceil(cnt/n))continue;
        if(a[i]<ceil(cnt/n)&&a[i]+m>=ceil(cnt/n)){
            maxx++;
            m-=(ceil(cnt/n)-a[i]);
        }
        else if(a[i]==ceil(cnt/n))maxx++;
    }
    cout<<maxx<<"\n";
    //cout<<ceil(cnt/n)<<"\n";
    return 0;
}
