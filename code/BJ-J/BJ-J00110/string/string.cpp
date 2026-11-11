#include<bits/stdc++.h>
using namespace std;
string s;
int S;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x,i,j;
    char c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>c;
        for(j=1;j<=x;j++){
            s+=c;
        }
    }
    for(i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]) S++;
    }
    cout<<S;
    return 0;
}
