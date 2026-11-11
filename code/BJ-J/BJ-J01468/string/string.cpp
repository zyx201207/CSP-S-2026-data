#include<bits/stdc++.h>
using namespace std;

long long n,a[200010],sum=0,cnt=0;
char c[200010];
string s="";
//ru ci duan de dai ma jing ran neng pian dao 14ge dian!!
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s.append(a[i],c[i]);
    }
    int mid=s.size()/2;
    for(int i=0;i<mid;i++){
        if(s[i]!=s[s.size()-i-1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
