#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(and.in;"r";stdin);
	freopen(and.out;"w";stdout);
	long long n,m,sum;
	cin >> n >> m;
	long long a[100005];
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(a[j] <= a[j-1]){
				sum = a[j];
				a[j] = a[j-1];
				a[j-1] = sum;
			}
		}
	}
	cout << a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
