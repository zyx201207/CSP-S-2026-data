#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,sum=0;
    string s;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>a;
        s.append(m,a);
    }
    for(int i=0,j=s.size()-1;i<=j;i++,j--)
    {
        if(s[i]!=s[j])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
