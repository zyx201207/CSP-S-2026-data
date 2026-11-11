#include<bits/stdc++.h>
using namespace std;
int n,s=0,sum=0,v=0;
string S[60000000];
int main(){
cin>>n;
    freopen("string","w",stdout);
    for(int i=1;i<=n;i++)
    {
        int l;
        string c;
        cin>>l>>c;
        for(int j=1;j<=l;j++)
        {
            S[s]=c;
            s+=1;
        }
    }
    if(s/2==0)
        v=s/2;
    else
        v=s/2+1;
    for(int i=0;i<=v;i++)
    {
        if(S[i]!=S[v-i])
        {
            S[v-i]=S[i];
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}
