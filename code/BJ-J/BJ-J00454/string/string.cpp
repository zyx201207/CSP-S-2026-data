#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt=0,sum=0;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    string arr,t;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        for(int j=1;j<=a[i];j++)arr+=c[i];
    }
    t=arr;
    reverse(t.begin(),t.end());
    for(int i=0;i<arr.size()/2+1;i++)if(arr[i]!=t[i])cnt++;
    cout<<cnt;
    return 0;
}
