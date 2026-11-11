#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char b[200010];
long long ret=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int j=n;
	for(int i=1;i<=n;i++){
		while(i<j&&a[i]>=a[j])a[i]-=a[j],ret+=(b[i]==b[j]?0:a[j]),j--;
		if(i>=j)break;
		ret+=(b[i]==b[j]?0:a[i]);
		a[j]-=a[i];
	}
	cout<<ret;
	return 0;
}
