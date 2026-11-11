#include<iostream>
#include<cstdio>
using namespace std;
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	long long a[10000000];
	cin >> n;
	for(int i=0;i<=n;i++){
		cin >> a[i];
		if(i==n){
			cout << a[i];
		}
	}
	return 0;
}

