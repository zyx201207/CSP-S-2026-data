#include <bits/stdc++.h>
using namespace std;
long long tentwo(long long n){
	int x=0,p=1;
	while(n>0){
		x+=(n%2)*p;
		n/=2;
		p*=10;
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long maxand=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((tentwo(i) & tentwo(j))>maxand){
				maxand=(i&j);
			}
		}
	}
	cout<<maxand;
}
