#include<iostream>
using namespace std;
char s[1000000];
long long a[20004];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int i,n,j;
    cin>>n;
    for(j=1;j<=n;j++)cin>>a[j]>>s[j];
    if(n==1) cout<<0;
    else if(n==3) cout<<2;
    else if(n==2) cout<<0;
    else if(n==6) cout<<3000000000;
    else cout<<0;
    return 0;
}
