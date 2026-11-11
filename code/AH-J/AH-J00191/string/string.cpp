#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,c=0,sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,j=1;i<=n;i++){
        int a;
        char m;
        cin>>a>>m;
        sum+=a;
        for(;j<=sum;j++){
            s[j]=m;
        }
    }
    for(int i=sum;i>sum/2;i--)s1[sum+1-i]=s[i];
    for(int i=1;i<=sum/2;i++){
        if(s[i]!=s1[i])c++;
    }
    cout<<c;
    return 0;
}
