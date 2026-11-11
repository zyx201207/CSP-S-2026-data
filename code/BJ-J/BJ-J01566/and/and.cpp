#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],lz=0;
//int ejz(int x){
    //int ans=0;
    //vector<int> c;
    //while(x>0){
        //int k=x%2;
        //c.push_back(k);
        //x/=2;
    //}
    //for(int i=c.size()-1;i>=0;i--)ans=ans*10+c[i];
    //return ans;
//}
int yu(int x,int y){
    return x&y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-m+1;i++){
        int sum=a[i];
        for(int j=i+1;j<=i+m-1;j++){
            sum=yu(sum,a[j]);
        }
        if(sum>lz)lz=sum;
    }
    cout<<lz;
    return 0;
}
