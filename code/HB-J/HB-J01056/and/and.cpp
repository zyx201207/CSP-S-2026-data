#include<bits/stdc++.h>
using namespace std;
map<int,string>s;
unsigned long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(a[i]!=0){
            s[i]+=to_string(a[1]%2);
            a[i]/=2;
        }
    }
    sort(s+1,s+n+1);
    string s1=s[1];
    for(int i=1;i<=m;i++){
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s[])
        }
    }
    cout<<b;
    return 0;
}
