#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],cnt;
char c[N];
vector<int> v;
string s;
signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n;
s=" "+s;
int mx=0x3f3f3f3f3f3f3f3f;
bool flag=0;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
    mx=min(mx,a[i]);
}
for(int i=1;i<=n;i++){
    if(a[i]!=mx) flag=1;
    a[i]-=mx-1;
    for(int j=1;j<=a[i];j++) s+=c[i];
}
if(flag==0){
    cout<<0;
    return 0;
}
int l=1,r=s.size()-1;
while(l<=r){
    if(s[l]!=s[r]) cnt++;
    l++;
    r--;
}
cout<<cnt*mx;
return 0;
}
