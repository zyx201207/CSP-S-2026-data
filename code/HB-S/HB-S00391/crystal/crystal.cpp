#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,sum=1,num,maxx=-1;
long long a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    num=m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        sum=1;
        num=m;
        for(int j=i+1;j<n;j++){
            if(a[i]-a[j]<=num){
                sum++;
                num-=(a[i]-a[j]);
            }
        }
        maxx=max(maxx,sum);
    }
    cout<<maxx;
    return 0;
}
