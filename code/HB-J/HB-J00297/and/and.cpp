#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20000005];
int maxn= EINTR;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdin);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];		
	}
	for(int i=1;i<+n;i++){
		int o=a[i];
		for(int j=i+1;i<+m;j++){
			o=o&&a[j];
		}
		maxn=max(o,maxn);
	}
	cout << maxn;
			
	return 0;
}
