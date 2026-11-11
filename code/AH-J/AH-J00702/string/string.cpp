#include<bits/stdc++.h>
using namespace std;
long long a[100000005],k,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai;
	char ci;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ai>>ci;
		while (ai--){
			k++;
			a[k]=ci-'a'+1;
		}
	}
	if (k%2==0){
		for (int i=k/2+1;i<=k;i++){
			if (a[i-k/2]!=a[i]) ans++;
		}
	}
	else {
		for (int i=k/2+2;i<=k;i++){
			if (a[i-k/2-1]!=a[i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
