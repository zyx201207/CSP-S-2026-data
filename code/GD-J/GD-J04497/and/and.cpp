#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long j[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
     int n,m;
     cin >> n >> m;
     for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    int t;
    for(int i=n;i>=n-2;i++){
    	t &= a[i];
	}
	cout <<t;
	return 0;
} 

