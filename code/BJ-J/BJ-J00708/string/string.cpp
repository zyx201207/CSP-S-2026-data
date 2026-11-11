#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
long long a1=1;
long long ans;
long long an;
char a[1000000000];
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        char q;
        cin>>x;
        cin>>q;
        ans+=x;
        for(long long j=1;j<=x;j++){
            a[a1]=q;
            a1++;
        }
    }
    for(long long i=1;i<=ans/2;i++){
        if(a[i]!=a[ans-i+1]){
            an++;
        }
    }
    cout<<an;
    return 0;
}





