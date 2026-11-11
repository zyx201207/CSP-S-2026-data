#include <bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=-1000000000000000000;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        long long num=a[i];
        for(int j=i+1;j<=i+m-1;j++){
            num=num&a[j];
        }
        maxn=max(maxn,num);
    }
    cout<<maxn;
	return 0;
}
