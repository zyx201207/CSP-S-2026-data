#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    unsigned long long n,m,ans=0,sum;
    cin>>n>>m;
    //cout<<1;
    vector<unsigned long long> a(n+1);
    //cout<<1;
    vector<int> i(m+1,0);
  //  cout<<1<<endl;
    for(unsigned long long j=1;j<=m;j++){
        i[j]=j;
    }
    while(1){
            sum=0;
        if(i[m]==n-m+1){
            break;
        }
        i[1]++;
        for(unsigned long long j=1;i[j]==n-j;j++){
            i[j+1]++;
            i[j]=i[j-1]+1;
        }
        sum=a[i[1]]&a[i[2]];
        for(unsigned long long j=3;j<=m;j++){
            sum=sum&a[i[j]];
        }
        if(sum>ans){
            ans=sum;
        }
    }
    cout<<ans<<endl;

    return 0;
}
