#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0,r;
    long long a;
    char b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    r=s.size()-1;
    long long sum=0;
    while(l<=r)
    {
     	if(s[l]!=s[r])
            sum++;
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}
