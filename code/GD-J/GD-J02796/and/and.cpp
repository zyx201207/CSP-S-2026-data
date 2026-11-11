#include<bits/stdc++.h>
using namespace std;
int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],maxx=-1;
	cin >> n >> m;
	for(long long i=1;i<n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int k=n,q=a[1];
	for(long long i=2;i<n;i++){
		if(m==1)break;
		q=q&a[i];
		if(q>maxx)maxx=q;
		m--;
	}
	cout << maxx;
} 
