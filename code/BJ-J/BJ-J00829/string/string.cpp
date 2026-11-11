#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
string s;
int check(string x){
    int ans=0;
    for(int i=0,j=x.size()-1;i<=j;i++,j--){
        if(x[i]!=x[j]){
            ans++;
        }
    }
    return ans;
}
signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    cout<<check(s)<<endl;

    return 0;
}
