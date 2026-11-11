#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1;
    int j=n-i+1;
    long long sum=0;
    while(i<j){
        int xiao=min(a[i],a[j]);
        a[i]-=xiao;
        a[j]-=xiao;
        if(c[i]!=c[j]){
            sum+=xiao;
        }
        // cout<<i<<" "<<j<<" "<<xiao<<endl;
        if(a[i]==0) i++;
        if(a[j]==0) j--;
    }
    cout<<sum<<endl;
}
