#include<bits/stdc++.h>
using namespace std;
int s[10000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.in","w",stdout);
    int n,m,num=0;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>a;
        for(int j=1;j<=m;j++)
        {
            s[j]+=a;
        }
        if(s.length%2==0)
        {
            s[m]!=s[n];
            num++;
        }
        else{
            s[m-1]!=s[n];
            num++;
        }
    }
    cout<<num;
}
