#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
string s;
int n;
int ans=0;
int cnt,bn;
signed main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
cin>>n;
while(n--){
int m;
string a;
cin>>m>>a;
for(int i=1;i<=m;i++)s+=a;
}
cnt=s.size();
bn=cnt/2;
for(int i=0;i<bn;i++){
if(s[i]!=s[cnt-1-i])ans+=1;

}cout<<ans;

return 0;
} 
