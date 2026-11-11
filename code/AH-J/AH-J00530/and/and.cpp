#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n];
    return 0;
}    
