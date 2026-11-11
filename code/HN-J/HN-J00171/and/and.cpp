#include<bits/stdc++.h>
using namespace std;
long long a[10000000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, s1=-1, s2=-1, s3=-1;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		if(a[i]>s1) s1=a[i];
		else if(a[i]>s2) s2=a[i];
		else if(a[i]>s3) s3=a[i];
	}
	cout << s3;
	return 0;
}
