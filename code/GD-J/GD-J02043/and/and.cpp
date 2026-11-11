#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1;
	
	for(int i=1;i<=n;i++){
		int a1=a[i];
		for(int j=i+1;j<=n;j++){
			int b=a[j];
			if(a1&b>maxn){
				maxn=a1&b;
			}
		}
	}
	cout<<maxn;
	return 0;
}
