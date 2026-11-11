#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long l[200005];
string c[200005];

int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n,r,l2,t=0;
    string s;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
        l[i]=i;
        r+=a[i];
    }

    for(long long i=0;i<n;i++){
        l2+=l[i];
    }

    int s=0;
    for(long long i=0;i<l.size();i++){
        if(c[i]==c[n-(i+1)]&&a[i]==a[n-(i+1)]){
            cout<<"0";
            return 0;
        }

    }
    cout<<t;
    return 0;
}
