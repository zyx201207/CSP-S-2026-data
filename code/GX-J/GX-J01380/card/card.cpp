#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
long long n,m,a[N];
map<char,long long> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s.find(a[j],0)&&s.find(a[j],0)+1!=0){
                long long u=s.find(a[j],0);
                s.erase(u);
            }else s+=a[j]+'0';
        }
        for(int k=0;k<s.size();k++) mp[s[k]]++;
    }
    for(int i=1;i<=m;i++) cout<<mp[i+'0']<<" ";
    return 0;
}
