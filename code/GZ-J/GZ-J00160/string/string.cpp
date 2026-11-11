//GZ-J00160 贵阳市第三中学 严介谦
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int m;char a;
        cin>>m>>a;
        for(int i=0;i<m;i++)
            s+=a;
    }long long l=s.size()/2,r=l;
    if(s.size()%2==0)
        l-=1;
    long long cnt=0;
    while(l>=0){
        if(s[l]!=s[r])
            cnt++;
        l--;
        r++;
    }cout<<cnt;
    return 0;
}
