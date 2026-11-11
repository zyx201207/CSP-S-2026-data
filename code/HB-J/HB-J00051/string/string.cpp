#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num;
    string s="";
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >>n;
for(int i=0;i<n;i++)
{
    string k;
    int m;
    cin>>m>>k;
 for(int j=0;j<m;j++)
{
    s+=k;
}
}
cout<<s;
return 0;
}
