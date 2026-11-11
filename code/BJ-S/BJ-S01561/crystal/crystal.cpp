#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num;
    long long c;
    long long sum;
}a[500010];
long long a_n[500010];
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a_n[i];
    sort(&a_n[0],&a_n[n]);
    for(int i=0;i<n;i++) a[i].num=a_n[i];
    for(int i=0;i<n-1;i++) a[i].c=a[i+1].num-a[i].num;
    a[n].c=0;a[n].sum=0;
    for(int i=n-1;i>=0;i--) a[i].c+=a[i+1].c;
    for(int i=n-1;i>=0;i--) a[i].sum=a[i+1].sum+a[i].c;
    int ans=0;
    for(int i=1;i<n;i++){
        ans++;
        if(m>=a[i-ans].sum-(a[i].sum+(a[i].c)*ans)) ans++;
        ans--;
    }
	cout<<ans+1;
    return 0;
}
