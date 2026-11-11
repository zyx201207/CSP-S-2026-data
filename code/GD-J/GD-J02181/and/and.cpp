#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long q=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n,cmp);
	q=a[1];
	for(int i=2;i<=m;i++){
		q=q & a[i];
	}
	cout<<q;
	
	return 0;
} 
