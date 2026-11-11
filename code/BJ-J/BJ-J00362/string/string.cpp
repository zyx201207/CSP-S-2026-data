#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N];
char b[N];
char c[N*200];
int main(){
    freopen("string.in","r",stdin);
    cin>>n;
    long long p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++) c[++p]=b[i];
    }
    long long sum=0;
    for(int i=1;i<=p;i++){
        if(c[i]!=c[p-i+1]) sum++;
    }
    freopen("string.out","w",stdout);
    cout<<sum;

}
