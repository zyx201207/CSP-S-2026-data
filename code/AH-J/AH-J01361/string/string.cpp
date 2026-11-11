#include<bits/stdc++.h>
using namespace std;
int n;
    string S="",S1="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            S+=c;
    }
    int ls=S.size()-1;

    int l=ls/2,r,cnt=0;
 if(ls%2==1)
 r=l+1;
 else
 r=l;
 while(l>=0&&r<=ls)
 {
     if(S[l]!=S[r])
        cnt++;
     l--;
     r++;
 }
 cout<<cnt;
 return 0;
}
