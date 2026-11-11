#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n;
int m;
long long ma=0;
cin>>n>>m;
vector<int>s(n);;
for(int i=0;i<n;i++){
    cin>>s[i];
    if(s[i]>ma)
    {
        ma=s[i];
    }
}
if(m==1)
{
    cout<<ma;
    return 0;
}
else if(m==n)
{
   cout<<0;
   return 0;
}
else{
    cout<<1;
}

return 0;
}
