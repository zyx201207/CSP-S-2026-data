#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long str[500001];
long long minn=INT_MIN;
long long sum,h=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    sum=m;
    for(long long i=1;i<=n;i++){
        cin>>str[i];
    }
    sort(str+1,str+n+1);
    for(long long i=n;i>=1;i--){
        for(long long j=i-1;j>=1;j--){
            sum=sum+str[i]-str[j];
            if(sum>m){
                break;
            }else{
                h++;
            }
        }
        if(h>minn){
            minn=h;
        }
        sum=0;
        h=1;
    }
    cout<<minn;
    return 0;
}
