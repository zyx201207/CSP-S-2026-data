#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-9999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		long long t=a[i];
		for(int j=i;j<=i+m-1;j++){
			t&=a[j];
		}
		if(t>maxx)maxx=t;
	}
	cout<<maxx;
	return 0;
}
