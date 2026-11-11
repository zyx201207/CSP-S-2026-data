#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,a,sum,sum1,l=1;
string s,p;
char a1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>a1;
        for(int i=0;i<a;i++){
            s+=a1;
        }sum+=a;
    }if(n<=1){
        cout<<0;
        return 0;
    }for(long long i=sum-1;i>=0;i--) p+=s[i];
    if(p!=s) l=0;
    if(l==1){
        cout<<0;
        return 0;
    }for(long long i=0;i<sum-1;i++){
        if(p[i]!=s[i]){
            s[i]=p[i];
            p[sum-1-i]=s[i];
            sum1++;
        }
    }
    cout<<sum1;
    return 0;
}
