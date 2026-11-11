#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]&a[i+1]>maxn){
			maxn=a[i]&a[i+1];
		}
	}
	cout<<maxn;
	return 0;
}	
