#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >>n >>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	cout <<a[n-m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
