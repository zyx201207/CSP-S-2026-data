#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,ans=1,sum=0;
    cin>>n;
    string c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
             s+=c;
        }
    }
    int l=0,h=s.size()-1;
    while(l<=h)
    {
        if(s[l]==s[h])
        {
            l+=1;
            h-=1;
        }
        else
        {
           sum+=1;
           l+=1;
           h-=1;
        }
    }
    cout<<sum;
}
