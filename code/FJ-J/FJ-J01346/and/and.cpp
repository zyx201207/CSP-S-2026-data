#include<bits/stdc++.h>
using namespace std;
long long a[2000005],c;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int j=1;j<=n-m;j++){
		if(c==0){
			c=a[j];
			for(long long i=j+1;i<=m+j-1;i++){
				c=c&a[i];
			}
		}
		if(c!=0){
			cout<<c;
			return 0;
		}
	}
	cout<<c;

	return 0;
}

