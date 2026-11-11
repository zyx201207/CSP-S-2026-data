#include <bits/stdc++.h>
using namespace std;
const long long N=100005;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n;
    long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long j=1;
	for(int i=1;i<=m;i++){
		if(a[i]>a[j]){
			j++;
		}
	}
	cout<<n-j+3;
	return 0;
}
