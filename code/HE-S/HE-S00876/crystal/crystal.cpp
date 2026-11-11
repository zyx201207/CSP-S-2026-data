#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	long long n,m;
	long long shu=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=a[1];i<=m;i++){
		a[i]+=1;
		if(a[i]==a[i+1]){
			shu++;
		}
		a[i+1];
	}
	cout<<shu;
	return 0;
}
