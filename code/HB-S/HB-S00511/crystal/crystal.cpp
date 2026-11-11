#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	for(int i=1;i<=n;i++){
		m-=i;
		if(m<0) {
			cout<<a[m];
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
